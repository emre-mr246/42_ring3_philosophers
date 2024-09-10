/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:02:21 by emgul             #+#    #+#             */
/*   Updated: 2024/09/10 15:28:40 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include <errno.h>
#include <unistd.h>

static void	handle_error(int status)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		write(2, ERR_EAGAIN, ft_strlen(ERR_EAGAIN));
	else if (status == ENOMEM)
		write(2, ERR_ENOMEM, ft_strlen(ERR_ENOMEM));
	else if (status == EPERM)
		write(2, ERR_EPERM, ft_strlen(ERR_EPERM));
	else if (status == EBUSY)
		write(2, ERR_EBUSY, ft_strlen(ERR_EBUSY));
	else if (status == ETIMEDOUT)
		write(2, ERR_ETIMEDOUT, ft_strlen(ERR_ETIMEDOUT));
	else if (status == EINVAL)
		write(2, ERR_EINVAL, ft_strlen(ERR_EINVAL));
	else if (status == ESRCH)
		write(2, ERR_ESRCH, ft_strlen(ERR_ESRCH));
	else if (status == EINTR)
		write(2, ERR_EINTR, ft_strlen(ERR_EINTR));
	else if (status == EDEADLK)
		write(2, ERR_EDEADLK, ft_strlen(ERR_EDEADLK));
	else
		write(2, ERR_UNKNOWN, ft_strlen(ERR_UNKNOWN));
}

void	handle_thread(pthread_t *thread, void *(*func)(void *), void *data,
		t_operation operation)
{
	int	status;

	if (operation == CREATE)
		status = pthread_create(thread, NULL, func, data);
	else if (operation == JOIN)
		status = pthread_join(*thread, NULL);
	else
		status = 0;
	handle_error(status);
}

void	handle_mutex(pthread_mutex_t *mutex, t_operation operation)
{
	int	status;

	if (operation == LOCK)
		status = pthread_mutex_lock(mutex);
	else if (operation == UNLOCK)
		status = pthread_mutex_unlock(mutex);
	else if (operation == INIT)
		status = pthread_mutex_init(mutex, NULL);
	else if (operation == DESTROY)
		status = pthread_mutex_destroy(mutex);
	else
	{
		write(2, ERR_INVCODE, ft_strlen(ERR_INVCODE));
		return ;
	}
	handle_error(status);
}
