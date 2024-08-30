/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:17:59 by emgul             #+#    #+#             */
/*   Updated: 2024/08/30 06:13:42 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	new;

	handle_mutex(mutex, LOCK);
	new = *value;
	handle_mutex(mutex, UNLOCK);
	return (new);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	new;

	handle_mutex(mutex, LOCK);
	new = *value;
	handle_mutex(mutex, UNLOCK);
	return (new);
}

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	handle_mutex(mutex, LOCK);
	*dest = value;
	handle_mutex(mutex, UNLOCK);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	handle_mutex(mutex, LOCK);
	*dest = value;
	handle_mutex(mutex, UNLOCK);
}

void	increase_long(pthread_mutex_t *mutex, long *value)
{
	handle_mutex(mutex, LOCK);
	(*value)++;
	handle_mutex(mutex, UNLOCK);
}
