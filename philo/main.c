/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:54:00 by emgul             #+#    #+#             */
/*   Updated: 2024/08/31 07:17:04 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (!(ac == 5 || ac == 6))
	{
		err_arg();
		return (-1);
	}
	init_table(&table);
	if (handle_input(table, av) == -1)
	{
		err_arg();
		clean(table);
		return (-1);
	}
	init_philos(table);
	init_forks(table);
	philosophers(table);
	clean(table);
	return (0);
}