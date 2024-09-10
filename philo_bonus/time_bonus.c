/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:00:08 by emgul             #+#    #+#             */
/*   Updated: 2024/09/10 15:08:19 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <sys/time.h>
#include <unistd.h>

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

static long	get_elapsed_usec(struct timeval start, struct timeval end)
{
	return (((end.tv_sec - start.tv_sec) * 1000000L) \
	+ (end.tv_usec - start.tv_usec));
}

void	usleep_lossless(long usec, t_table *table)
{
	struct timeval	start;
	struct timeval	current;
	long			elapsed;
	long			remaining;

	elapsed = 0;
	gettimeofday(&start, NULL);
	while (elapsed < usec)
	{
		gettimeofday(&current, NULL);
		if (get_bool(table->table_sem, &table->dinner_over))
			break ;
		elapsed = get_elapsed_usec(start, current);
		remaining = usec - elapsed;
		if (remaining > 1000)
			usleep(remaining / 2);
	}
}
