/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:54:00 by emgul             #+#    #+#             */
/*   Updated: 2024/08/30 13:19:27 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo_bonus.h"

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
		return (-1);
	}
	init_philos(table);
	table->forks = create_sem("forks_sem", table->philo_count);
	table->wait_for_second_sem = create_sem("second_fork_sem", 1);
	dinner(table);
	clean(table);
	return (0);
}
