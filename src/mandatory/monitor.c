/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:33:34 by emgul             #+#    #+#             */
/*   Updated: 2024/08/30 13:02:40 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static bool	all_threads_running(pthread_mutex_t *mutex, long *threads,
		long philo_count)
{
	bool	ret;

	ret = false;
	handle_mutex(mutex, LOCK);
	if (*threads == philo_count)
		ret = true;
	handle_mutex(mutex, UNLOCK);
	return (ret);
}

static bool	philo_died(t_table *table, t_philo *philo)
{
	long	elapsed_time;

	if (get_bool(&philo->philo_mutex, &philo->is_full))
		return (false);
	elapsed_time = get_time_ms() - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	if (elapsed_time > table->time_to_die)
		return (true);
	else
		return (false);
}

void	*watch_dinner(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!all_threads_running(&table->table_mutex,
			&table->running_threads_count, table->philo_count))
		continue ;
	usleep_lossless(10000, table);
	while (!get_bool(&table->table_mutex, &table->dinner_over))
	{
		i = 0;
		while (i < table->philo_count)
		{
			if (philo_died(table, table->philos[i]))
			{
				print_status(DIED, table, table->philos[i]);
				set_bool(&table->table_mutex, &table->dinner_over, true);
			}
			i++;
		}
		if (get_long(&table->table_mutex,
				&table->full_philo_count) == table->philo_count)
			set_bool(&table->table_mutex, &table->dinner_over, true);
	}
	return (NULL);
}
