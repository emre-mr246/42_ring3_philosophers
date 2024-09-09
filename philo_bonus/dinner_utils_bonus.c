/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:32:34 by emgul             #+#    #+#             */
/*   Updated: 2024/08/31 00:48:56 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <unistd.h>
#include <stdio.h>

void	print_status(t_philo_status status, t_table *table, t_philo *philo)
{
	long	elapsed_time;

	if (get_bool(philo->philo_sem, &philo->is_full))
		return ;
	handle_sem(table->print_sem, LOCK);
	if (!get_bool(table->table_sem, &table->dinner_over))
	{
		elapsed_time = (get_time_ms() - table->start_time);
		if (status == TAKE_A_FORK)
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
	handle_sem(table->print_sem, UNLOCK);
}

void	lone_philo(t_table *table, t_philo *philo)
{
	increase_long(table->table_sem, &table->running_threads_count);
	set_long(philo->philo_sem, &philo->last_meal_time, table->start_time);
	print_status(TAKE_A_FORK, table, philo);
}

int	take_two_forks(t_table *table, t_philo *philo)
{
	sem_wait(table->second_fork_sem);
	if (sem_wait(table->forks) == 0)
	{
		print_status(TAKE_A_FORK, table, philo);
		if (sem_wait(table->forks) == 0)
		{
			sem_post(table->second_fork_sem);
			print_status(TAKE_A_FORK, table, philo);
			return (0);
		}
		sem_post(table->forks);
	}
	return (-1);
}

void	put_down_forks(t_table *table)
{
	sem_post(table->forks);
	sem_post(table->forks);
}
