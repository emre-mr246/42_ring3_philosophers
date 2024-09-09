/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:47:06 by emgul             #+#    #+#             */
/*   Updated: 2024/08/31 07:14:56 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_table *table, t_philo *philo)
{
	if (get_bool(&table->table_mutex, &table->dinner_over))
		return ;
	handle_mutex(&philo->left_fork->mutex, LOCK);
	print_status(TAKE_FIRST_FORK, table, philo);
	handle_mutex(&philo->right_fork->mutex, LOCK);
	print_status(TAKE_SECOND_FORK, table, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time_ms());
	print_status(EATING, table, philo);
	increase_long(&philo->philo_mutex, &philo->meals_counter);
	usleep_lossless(table->time_to_eat, table);
	if (!get_bool(&philo->philo_mutex, &philo->is_full)
		&& get_long(&philo->philo_mutex,
			&philo->meals_counter) == table->max_meal_per_philo)
	{
		set_bool(&philo->philo_mutex, &philo->is_full, true);
		increase_long(&table->table_mutex, &table->full_philo_count);
	}
	handle_mutex(&philo->left_fork->mutex, UNLOCK);
	handle_mutex(&philo->right_fork->mutex, UNLOCK);
}

static void	sleeping(t_table *table, t_philo *philo)
{
	print_status(SLEEPING, table, philo);
	usleep_lossless(table->time_to_sleep, table);
}

void	thinking(t_table *table, t_philo *philo, bool dinner_started)
{
	long	think_time;

	if (dinner_started)
		print_status(THINKING, table, philo);
	if (table->philo_count % 2 != 0)
	{
		think_time = (table->time_to_eat * 2) - table->time_to_sleep;
		if (think_time > 0)
			usleep_lossless((think_time * 50) / 100, table);
	}
}

static void	*start_routine(void *data)
{
	t_table	*table;
	t_philo	*philo;

	philo = (t_philo *)data;
	table = philo->table;
	while (!get_bool(&table->table_mutex, &table->all_threads_ready))
		continue ;
	if (table->philo_count == 1)
	{
		lone_philo(table, philo);
		return (NULL);
	}
	increase_long(&table->table_mutex, &table->running_threads_count);
	set_long(&philo->philo_mutex, &philo->last_meal_time, table->start_time);
	wait_some_philos(table, philo);
	while (!get_bool(&table->table_mutex, &table->dinner_over))
	{
		if (get_bool(&philo->philo_mutex, &philo->is_full))
			break ;
		eating(table, philo);
		sleeping(table, philo);
		thinking(table, philo, true);
	}
	return (NULL);
}

int	philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		handle_thread(&table->philos[i]->thread_id, start_routine,
			table->philos[i], CREATE);
		i++;
	}
	table->start_time = get_time_ms();
	handle_thread(&table->camera, watch_routine, table, CREATE);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = 0;
	while (i < table->philo_count)
	{
		handle_thread(&table->philos[i]->thread_id, NULL, NULL, JOIN);
		i++;
	}
	handle_thread(&table->camera, NULL, NULL, JOIN);
	set_bool(&table->table_mutex, &table->dinner_over, true);
	return (1);
}
