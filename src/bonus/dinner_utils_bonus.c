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

#include "../../inc/philo_bonus.h"
#include "../../lib/libft/inc/libft.h"
#include <unistd.h>

void	print_status(t_philo_status status, t_table *table, t_philo *philo)
{
	long	elapsed_time;

	if (get_bool(philo->philo_sem, &philo->is_full))
		return ;
	handle_sem(table->print_sem, LOCK);
	if (!get_bool(table->table_sem, &table->dinner_over))
	{
		elapsed_time = (get_time_ms() - table->start_time);
		ft_printf("%i %i ", (int *)elapsed_time, philo->id);
		if (status == TAKE_A_FORK)
			write(1, "has taken a fork\n", 17);
		else if (status == EATING)
			write(1, "is eating\n", 10);
		else if (status == SLEEPING)
			write(1, "is sleeping\n", 12);
		else if (status == THINKING)
			write(1, "is thinking\n", 12);
		else if (status == DIED)
			write(1, "died\n", 5);
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
