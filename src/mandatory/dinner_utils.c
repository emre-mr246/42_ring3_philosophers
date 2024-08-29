/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:32:34 by emgul             #+#    #+#             */
/*   Updated: 2024/08/29 11:45:50 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"
#include "../../lib/libft/inc/libft.h"
#include <unistd.h>

void print_status(t_philo_status status, t_table *table, t_philo *philo)
{
	long elapsed_time;
	char *tmp;

	if (get_bool(&philo->philo_mutex, &philo->is_full))
		return ;
	handle_mutex(&table->print_mutex, LOCK);
	if (!get_bool(&table->table_mutex, &table->dinner_over))
	{
		elapsed_time = (get_time_milisec() - table->start_time);
		tmp = ft_itoa(elapsed_time);
		write(1, tmp, ft_strlen(tmp));
		write(1, " ", 1);
		tmp = ft_itoa(philo->id);
		write(1, tmp, ft_strlen(tmp));
		if (status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
			write(1, " has taken a fork\n", 18);
		else if (status == EATING)
			write(1, " is eating\n", 11);
		else if (status == SLEEPING)
			write(1, " is sleeping\n", 13);
		else if (status == THINKING)
			write(1, " is thinking\n", 13);
		else if (status == DIED)
			write(1, " died\n", 6);
	}
	handle_mutex(&table->print_mutex, UNLOCK);
}

void lone_philo(t_table *table, t_philo *philo)
{
	while(!get_bool(&table->table_mutex, &table->all_threads_ready))
		continue ;
	increase_long(&table->table_mutex, &table->running_threads_count);
	set_long(&philo->philo_mutex, &philo->last_meal_time, table->start_time);
	usleep(table->time_to_die);
}

void wait_some_philos(t_table *table, t_philo *philo)
{
	if (table->philo_count % 2 == 0)
		if (philo->id % 2 == 0)
			usleep_lossless(50000, table);
	else
		if (philo->id % 2)
			thinking(table, philo, false);
}
