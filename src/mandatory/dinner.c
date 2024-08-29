/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:47:06 by emgul             #+#    #+#             */
/*   Updated: 2024/08/29 07:41:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void eating(t_table *table, t_philo *philo)
{
	if (get_bool(&table->table_mutex, &table->dinner_over))
		return ;
	handle_mutex(&philo->left_fork->mutex, LOCK);
	print_status(TAKE_FIRST_FORK, table, philo);
	handle_mutex(&philo->right_fork->mutex, LOCK);
	print_status(TAKE_SECOND_FORK, table, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time_milisec());
	print_status(EATING, table, philo);
	increase_long(&philo->philo_mutex, &philo->meals_counter);
	if (!get_bool(&philo->philo_mutex, &philo->is_full) && table->max_meal_per_philo > 0 && get_long(&philo->philo_mutex, &philo->meals_counter) == table->max_meal_per_philo)
	{
		set_bool(&philo->philo_mutex, &philo->is_full, true);
		increase_long(&table->table_mutex, &table->full_philo_count);
	}
	usleep_lossless(table->time_to_eat, table);
	handle_mutex(&philo->left_fork->mutex, UNLOCK);
	handle_mutex(&philo->right_fork->mutex, UNLOCK);
}

static void sleeping(t_table *table, t_philo *philo)
{
	print_status(SLEEPING, table, philo);
	usleep_lossless(table->time_to_sleep, table);
}

void thinking(t_table *table, t_philo *philo)
{
	long t_think;

	print_status(THINKING, table, philo);
	if (table->philo_count % 2 == 0)
		return ;
	t_think = (table->time_to_eat * 2) - table->time_to_sleep;
	if (t_think > 0)
		usleep_lossless((t_think * 50) / 100, table);
}

static void *start_dinner(void *data)
{
	t_table *table;
	t_philo *philo;

	philo = (t_philo *)data;
	table = philo->table; 
	if (table->philo_count == 1)
	{
		lone_philo(table, philo);
		return (NULL);
	}
	while(!get_bool(&table->table_mutex, &table->all_threads_ready))
		continue ;
	increase_long(&table->table_mutex, &table->running_threads_count);
	set_long(&philo->philo_mutex, &philo->last_meal_time, table->start_time);
	de_synchronize_philos(table, philo);
	while(!get_bool(&table->table_mutex, &table->dinner_over))
	{
		if (get_bool(&philo->philo_mutex, &philo->is_full))
			break ;
		eating(table, philo);
		sleeping(table, philo);
		thinking(table, philo);
	}
	return (NULL);
}

int dinner(t_table *table)
{
	int i;

	i = 0;
	while (i < table->philo_count)
	{
		handle_thread(&table->philos[i]->thread_id, start_dinner, table->philos[i], CREATE);
		i++;
	}	
	table->start_time = get_time_milisec();
	handle_thread(&table->camera, watch_dinner, table, CREATE);
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