/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 07:51:53 by emgul             #+#    #+#             */
/*   Updated: 2024/08/07 14:17:54 by emgul            ###   ########.fr       */
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
}

/*
 * @brief Converts a string to an long.
 *
 * @param str The string to convert,
 *  which may include optional whitespace and a sign.
 * @return The long representation of the string.
 */
long	ft_atol(const char *str)
{
	long	result;
	int	sign;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}
