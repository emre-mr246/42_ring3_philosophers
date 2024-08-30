/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_set_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:17:59 by emgul             #+#    #+#             */
/*   Updated: 2024/08/30 09:40:37 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo_bonus.h"

bool	get_bool(sem_t *sem, bool *value)
{
	bool	new;

	handle_sem(sem, LOCK);
	new = *value;
	handle_sem(sem, UNLOCK);
	return (new);
}

long	get_long(sem_t *sem, long *value)
{
	long	new;

	handle_sem(sem, LOCK);
	new = *value;
	handle_sem(sem, UNLOCK);
	return (new);
}

void	set_bool(sem_t *sem, bool *dest, bool value)
{
	handle_sem(sem, LOCK);
	*dest = value;
	handle_sem(sem, UNLOCK);
}

void	set_long(sem_t *sem, long *dest, long value)
{
	handle_sem(sem, LOCK);
	*dest = value;
	handle_sem(sem, UNLOCK);
}

void	increase_long(sem_t *sem, long *value)
{
	handle_sem(sem, LOCK);
	(*value)++;
	handle_sem(sem, UNLOCK);
}
