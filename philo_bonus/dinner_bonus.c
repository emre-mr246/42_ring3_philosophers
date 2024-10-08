/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:47:06 by emgul             #+#    #+#             */
/*   Updated: 2024/09/10 15:07:18 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	eating(t_table *table, t_philo *philo)
{
	if (get_bool(table->table_sem, &table->dinner_over))
		return ;
	take_two_forks(table, philo);
	set_long(philo->philo_sem, &philo->last_meal_time, get_time_ms());
	print_status(EATING, table, philo);
	increase_long(philo->philo_sem, &philo->meals_counter);
	increase_long(table->table_sem, &table->ate_philo_count);
	usleep_lossless(table->time_to_eat, table);
	if (!get_bool(philo->philo_sem, &philo->is_full)
		&& get_long(philo->philo_sem,
			&philo->meals_counter) == table->max_meal_per_philo)
	{
		set_bool(philo->philo_sem, &philo->is_full, true);
		increase_long(table->table_sem, &table->full_philo_count);
	}
	put_down_forks(table);
}

static void	sleeping(t_table *table, t_philo *philo)
{
	print_status(SLEEPING, table, philo);
	usleep_lossless(table->time_to_sleep, table);
}

static void	thinking(t_table *table, t_philo *philo, bool dinner_started)
{
	if (dinner_started)
		print_status(THINKING, table, philo);
	if (get_long(table->table_sem,
			&table->ate_philo_count) != table->philo_count)
		usleep_lossless(100, table);
	set_long(table->table_sem, &table->ate_philo_count, 0);
}

static void	*start_routine(void *data)
{
	t_table	*table;
	t_philo	*philo;

	philo = (t_philo *)data;
	table = philo->table;
	while (!get_bool(table->table_sem, &table->all_threads_ready))
		continue ;
	if (table->philo_count == 1)
	{
		lone_philo(table, philo);
		return (NULL);
	}
	increase_long(table->table_sem, &table->running_threads_count);
	set_long(philo->philo_sem, &philo->last_meal_time, table->start_time);
	while (!get_bool(table->table_sem, &table->dinner_over))
	{
		if (get_bool(philo->philo_sem, &philo->is_full))
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
	set_bool(table->table_sem, &table->all_threads_ready, true);
	i = 0;
	while (i < table->philo_count)
	{
		handle_thread(&table->philos[i]->thread_id, NULL, NULL, JOIN);
		i++;
	}
	handle_thread(&table->camera, NULL, NULL, JOIN);
	set_bool(table->table_sem, &table->dinner_over, true);
	return (1);
}
