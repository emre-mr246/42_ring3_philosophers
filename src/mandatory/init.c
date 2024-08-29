/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:58:49 by emgul             #+#    #+#             */
/*   Updated: 2024/08/29 07:33:47 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"
#include "../../lib/libft/inc/libft.h"

int init_philos(t_table *table)
{
	t_philo **philos;
	t_philo *philo;
	int i;

	philos = (t_philo **)ft_calloc(sizeof(t_philo *), table->philo_count);
	if (!philos)
		return (-1);
	i = 0;
	while (i < table->philo_count)
	{
	 	philo = (t_philo *)ft_calloc(sizeof(t_philo), 1);
		if (!philo)
			return (-1);
		philo->id = i + 1;
		philo->table = table;
		handle_mutex(&philo->philo_mutex, INIT);
		philos[i] = philo;
		i++;
	}
	table->philos = philos;
	return (0);
}


int init_table(t_table **table)
{
	t_table *tmp;

	tmp = (t_table *)ft_calloc(sizeof(t_table), 1);
	if (!tmp)
		return (-1);
	*table = tmp;
	return (0);	
}

static void assign_forks(t_table *table, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		philo->left_fork = table->forks[philo->id % table->philo_count];
		philo->right_fork = table->forks[philo->id - 1];
	}
	else
	{
		philo->left_fork = table->forks[philo->id - 1];
		philo->right_fork = table->forks[philo->id % table->philo_count];
	}
}

int init_forks(t_table *table)
{
	t_fork **forks;
	t_fork *fork;
	int i;
	
	forks = (t_fork **)ft_calloc(sizeof(t_fork *), table->philo_count);
	if (!forks)
		return (-1);
	i = -1;
	while (++i < table->philo_count)
	{
		fork = (t_fork *)ft_calloc(sizeof(t_fork), 1);
		if (!fork)
			return (-1);
		handle_mutex(&fork->mutex, INIT);
		fork->id = i;
		forks[i] = fork;
	}
	table->forks = forks;
	i = -1;
	while (++i < table->philo_count)
		assign_forks(table, table->philos[i]);
	return (0);	
}
