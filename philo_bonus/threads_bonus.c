/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:02:21 by emgul             #+#    #+#             */
/*   Updated: 2024/08/31 07:19:33 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "error_bonus.h"
#include <errno.h>
#include <fcntl.h>
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

sem_t	*create_sem(char *name, int value)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT, 0644, value);
	return (sem);
}

void	handle_sem(sem_t *sem, t_operation operation)
{
	int	status;

	if (operation == LOCK)
		status = sem_wait(sem);
	else if (operation == UNLOCK)
		status = sem_post(sem);
	else if (operation == DESTROY)
		status = sem_close(sem);
	else
	{
		write(2, ERR_INVCODE, ft_strlen(ERR_INVCODE));
		return ;
	}
	handle_error(status);
}
