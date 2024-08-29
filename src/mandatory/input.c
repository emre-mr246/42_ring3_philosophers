/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:13:45 by emgul             #+#    #+#             */
/*   Updated: 2024/08/29 15:16:02 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"
#include "../../lib/libft/inc/libft.h"
#include <limits.h>

static int	check_input(char **av)
{
	int		i;
	long	tmp;

	i = 1;
	while (av[i])
	{
		if (ft_issign(av[i] == 0) || ft_isdigit(av[i] == 0))
			return (-1);
		tmp = ft_atol(av[i]);
		if (tmp <= 0)
			return (-1);
		if (tmp > INT_MAX)
			return (-1);
		i++;
	}
	return (1);
}

static void	seconds_to_miliseconds(t_table *table)
{
	table->time_to_eat *= 1000;
	table->time_to_sleep *= 1000;
}

int	handle_input(t_table *table, char **av)
{
	if (check_input(av) == -1)
		return (-1);
	table->philo_count = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (table->philo_count == 0)
		return (-1);
	if (table->time_to_die < 60 || table->time_to_eat < 60
		|| table->time_to_sleep < 60)
		return (-1);
	seconds_to_miliseconds(table);
	table->max_meal_per_philo = ft_atol(av[5]);
	if (!av[5])
		table->max_meal_per_philo = INT_MAX;
	else if (table->max_meal_per_philo <= 0)
		return (-1);
	return (0);
}
