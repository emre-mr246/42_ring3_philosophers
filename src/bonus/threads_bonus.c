/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:02:21 by emgul             #+#    #+#             */
/*   Updated: 2024/08/30 14:03:03 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo_bonus.h"
#include "../../lib/libft/inc/libft.h"
#include <errno.h>
#include <fcntl.h>

static void	handle_thread_error(int status, t_operation operation)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		ft_putendl_fd("Error: No resources for a new thread.\n", 2);
	else if (status == ENOMEM)
		ft_putendl_fd("Error: Insufficient memory to manage a thread.\n", 2);
	else if (status == EPERM)
		ft_putendl_fd("Error: Insufficient permissions to create a thread.\n",
			2);
	else if (status == EBUSY)
		ft_putendl_fd("Error: The mutex or resource is already busy.\n", 2);
	else if (status == ETIMEDOUT)
		ft_putendl_fd("Error: Thread operation timed out.\n", 2);
	else if (status == EINVAL && operation == CREATE)
		ft_putendl_fd("Error: Invalid attributes for thread creation.\n", 2);
	else if (status == EINVAL && operation == JOIN)
		ft_putendl_fd("Error: Thread is not joinable.\n", 2);
	else if (status == ESRCH)
		ft_putendl_fd("Error: No thread found with the specified ID.\n", 2);
	else if (status == EINTR)
		ft_putendl_fd("Error: Operation was interrupted by a signal.\n", 2);
	else if (status == EDEADLK)
		ft_putendl_fd("Error: Deadlock detected.\n", 2);
	else
		ft_putendl_fd("Error: An unknown thread error occurred.\n", 2);
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
	handle_thread_error(status, operation);
}

static void	handle_semaphore_error(int status)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		ft_putendl_fd("Error: No resources to lock the semaphore.\n", 2);
	else if (status == ENOMEM)
		ft_putendl_fd("Error: Insufficient memory.\n", 2);
	else if (status == EPERM)
		ft_putendl_fd("Error: Insufficient permissions.\n", 2);
	else if (status == EBUSY)
		ft_putendl_fd("Error: Semaphore is already locked.\n", 2);
	else if (status == ETIMEDOUT)
		ft_putendl_fd("Error: Semaphore operation timed out.\n", 2);
	else if (status == EINVAL)
		ft_putendl_fd("Error: Semaphore is not valid or uninitialized.\n", 2);
	else if (status == ESRCH)
		ft_putendl_fd("Error: Semaphore not found.\n", 2);
	else if (status == EINTR)
		ft_putendl_fd("Error: Semaphore was interrupted by a signal.\n", 2);
	else if (status == EDEADLK)
		ft_putendl_fd("Error: Deadlock detected for a semaphore.\n", 2);
	else
		ft_putendl_fd("Error: An unknown semaphore error occurred.\n", 2);
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
		ft_putendl_fd("Invalid operation code", 2);
		return ;
	}
	handle_semaphore_error(status);
}
