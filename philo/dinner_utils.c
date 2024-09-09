/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:32:34 by emgul             #+#    #+#             */
/*   Updated: 2024/08/31 05:18:30 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	print_status(t_philo_status status, t_table *table, t_philo *philo)
{
	long	elapsed_time;

	if (get_bool(&philo->philo_mutex, &philo->is_full))
		return ;
	handle_mutex(&table->print_mutex, LOCK);
	if (!get_bool(&table->table_mutex, &table->dinner_over))
	{
		elapsed_time = (get_time_ms() - table->start_time);
		if (status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
			printf("%li %i has taken a fork\n", elapsed_time, philo->id);
		else if (status == EATING)
			printf("%li %i is eating\n", elapsed_time, philo->id);
		else if (status == SLEEPING)
			printf("%li %i is sleeping\n", elapsed_time, philo->id);
		else if (status == THINKING)
			printf("%li %i is thinking\n", elapsed_time, philo->id);
		else if (status == DIED)
			printf("%li %i died\n", elapsed_time, philo->id);
	}
	handle_mutex(&table->print_mutex, UNLOCK);
}

void	lone_philo(t_table *table, t_philo *philo)
{
	increase_long(&table->table_mutex, &table->running_threads_count);
	set_long(&philo->philo_mutex, &philo->last_meal_time, table->start_time);
	print_status(TAKE_FIRST_FORK, table, philo);
}

void	wait_some_philos(t_table *table, t_philo *philo)
{
	if (table->philo_count % 2 == 0 && philo->id % 2 == 0)
		usleep_lossless(50000, table);
}
