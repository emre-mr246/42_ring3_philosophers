/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:54:00 by emgul             #+#    #+#             */
/*   Updated: 2024/08/07 16:11:44 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"
#include "../../lib/libft/inc/libft.h"

int main(int ac, char **av)
{
	t_table *table;

    if (!(ac == 5 || ac == 6))
	{
        err_arg();
		return (-1);
	}
	table = init_table();
	if (handle_input(table, av) == -1)
		return (-1);
	

}
