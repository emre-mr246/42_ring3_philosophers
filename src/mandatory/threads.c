/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:02:21 by emgul             #+#    #+#             */
/*   Updated: 2024/08/29 11:58:11 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/inc/libft.h"
#include "../../inc/philo.h"
#include <errno.h>

static void handle_thread_error(int status, t_operation operation)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		ft_putendl_fd("Error: No resources for a new thread.\n", 2);
	else if (status == ENOMEM)
		ft_putendl_fd("Error: Insufficient memory to manage a thread.\n", 2);
	else if (status == EPERM)
		ft_putendl_fd("Error: Insufficient permissions to create a thread.\n", 2);
	else if (status == EBUSY)
		ft_putendl_fd("Error: The mutex or resource is already busy.\n", 2);
	else if (status == ETIMEDOUT)
		ft_putendl_fd("Error: Thread operation timed out.\n", 2);
	else if (status == EINVAL && operation == CREATE)
		ft_putendl_fd("Error: Invalid attributes for thread creation.\n", 2);
	else if (status == EINVAL && (operation == JOIN || operation == DETACH))
		ft_putendl_fd("Error: Thread is not joinable or detachable.\n", 2);
	else if (status == ESRCH)
		ft_putendl_fd("Error: No thread found with the specified ID.\n", 2);
	else if (status == EINTR)
		ft_putendl_fd("Error: Operation was interrupted by a signal.\n", 2);
	else if (status == EDEADLK)
		ft_putendl_fd("Error: Deadlock detected.\n", 2);
	else
		ft_putendl_fd("Error: An unknown thread error occurred.\n", 2);
}

void handle_thread(pthread_t *thread, void *(*func)(void *), void *data, t_operation operation)
{
	int status;

	if (operation == CREATE)
		status = pthread_create(thread, NULL, func, data);
	else if (operation == JOIN)
		status = pthread_join(*thread, NULL);		
	else if (operation == DETACH)
		status = pthread_detach(*thread);
	else
		status = 0;
	handle_thread_error(status, operation);
}

static void	handle_mutex_error(int status, t_operation operation)
{
	if (status == 0)
		return ;
	if (status == EBUSY)
		ft_putendl_fd("Error: Mutex is already locked.", 2);
	else if (status == ENOMEM)
		ft_putendl_fd("Error: Not enough memory to create mutex.", 2);
	else if (status == EPERM)
		ft_putendl_fd("Error: No permission. Mutex is not locked by this thread.", 2);
	else if (status == EDEADLK)
		ft_putendl_fd("Error: Deadlock detected. Thread cannot proceed.", 2);
	else if (status == EINVAL)
	{
		if (operation == INIT)
			ft_putendl_fd("Error: Invalid initialization attribute for mutex.", 2);
		else
			ft_putendl_fd("Error: Invalid mutex value.", 2);
	}
	else if (status == EAGAIN)
		ft_putendl_fd("Error: Resources temporarily unavailable for mutex.", 2);
	else if (status == EINVAL)
		ft_putendl_fd("Error: Invalid argument passed to mutex function.", 2);
	else
		ft_putendl_fd("Error: Unknown error code.", 2);
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
		ft_putendl_fd("Invalid operation code", 2);
		return ;
	}
	handle_mutex_error(status, operation);
}
