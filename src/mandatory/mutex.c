/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:02:10 by emgul             #+#    #+#             */
/*   Updated: 2024/08/29 07:31:45 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"
#include "../../lib/libft/inc/libft.h"
#include <errno.h>

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
		ft_putendl_fd("Error: System resources temporarily unavailable for mutex operation.", 2);
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
