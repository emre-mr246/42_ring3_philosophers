/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:58:49 by emgul             #+#    #+#             */
/*   Updated: 2024/08/07 22:24:07 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"
#include "../../lib/libft/inc/libft.h"

t_philo *init_philos(t_table *table)
{
	t_philo *philo;
	int i;

 	philo = ft_calloc(sizeof( t_philo),table->philo_count);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < table->philo_count)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->is_full = false;
		i++;
	}
	return (philo);
}

t_fork *init_forks(t_table *table)
{
	t_fork *fork;

	fork = ft_calloc(sizeof(t_fork), table->philo_count);
	if (!fork)
		return (NULL);
	return (fork);
}

void assign_forks(t_table *table)
{
	t_philo *philo;

	philo = table->philos;
	if (philo->id % 2 == 0)
	{
		philo->left_fork = &table->forks[philo->id - 1];
		philo->right_fork = &table->forks[philo->id % table->philo_count];
	}
	else
	{
		philo->left_fork = &table->forks[philo->id % table->philo_count];
		philo->right_fork = &table->forks[philo->id - 1];
	}
}

t_table *init_table()
{
	t_table *table;
	int i;

	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	if (!table)
		return (NULL);
	table->philos = init_philos(table);
	table->forks = init_forks(table);
	assign_forks(table);
	i = 0;
	while (i < table->philo_count)
	{
		handle_mutex(&table->forks[i].fork, INIT);
		table->forks[i].id = i;
		i++;
	}
	philo_init(table);
	return (table);	
}
