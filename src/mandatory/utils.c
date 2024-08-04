/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 07:51:53 by emgul             #+#    #+#             */
/*   Updated: 2024/08/04 08:20:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/inc/libft.h"

void err_arg(void)
{
	ft_putendl_fd("Usage: ./philo 5 800 200 200 7", 2);
	ft_putendl_fd("Number of philosophers: 5", 2);
	ft_putendl_fd("Time before a philosopher dies if they don't eat: 800 ms", 2);
	ft_putendl_fd("Time it takes for a philosopher to eat: 200 ms", 2);
	ft_putendl_fd("Time it takes for a philosopher to sleep: 200 ms", 2);
	ft_putendl_fd("Number of times each philosopher needs to eat before the program terminates: 7", 2);
	exit(-1);
}

void exit_with_msg(char *error)
{
	ft_putendl_fd(error, 2);
	exit(-1);
}