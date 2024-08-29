/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:54:00 by emgul             #+#    #+#             */
/*   Updated: 2024/08/29 07:49:23 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int main(int ac, char **av)
{
	t_table *table;

    if (!(ac == 5 || ac == 6))
	{
        err_arg();
		return (-1);
	}
	init_table(&table);
	if (handle_input(table, av) == -1)
	{
        err_arg();
		return (-1);
	}
	init_philos(table);
	init_forks(table);
	dinner(table);
	clean(table);
	return (0);
}
