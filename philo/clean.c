/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:06:17 by emgul             #+#    #+#             */
/*   Updated: 2024/09/10 15:29:20 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	clean(t_table *table)
{
	int	i;

	i = 0;
	while (table->philos && i < table->philo_count)
	{
		handle_mutex(&table->philos[i]->philo_mutex, DESTROY);
		if (table->forks[i])
			free(table->forks[i]);
		if (table->philos[i])
			free(table->philos[i]);
		i++;
	}
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	handle_mutex(&table->table_mutex, DESTROY);
	handle_mutex(&table->print_mutex, DESTROY);
	if (table)
		free(table);
}
