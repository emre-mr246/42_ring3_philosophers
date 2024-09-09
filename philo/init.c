/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:58:49 by emgul             #+#    #+#             */
/*   Updated: 2024/08/31 01:01:28 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	init_philos(t_table *table)
{
	t_philo	**philos;
	t_philo	*philo;
	int		i;

	philos = (t_philo **)malloc(sizeof(t_philo *) * table->philo_count);
	if (!philos)
		return (-1);
	i = 0;
	while (i < table->philo_count)
	{
		philo = (t_philo *)malloc(sizeof(t_philo));
		if (!philo)
			return (-1);
		philo->id = i + 1;
		philo->is_full = false;
		philo->last_meal_time = 0;
		philo->left_fork = NULL;
		philo->meals_counter = 0;
		philo->right_fork = NULL;
		philo->thread_id = -1;
		philo->table = table;
		handle_mutex(&philo->philo_mutex, INIT);
		philos[i] = philo;
		i++;
	}
	table->philos = philos;
	return (0);
}

int	init_table(t_table **table)
{
	t_table	*tmp;

	tmp = (t_table *)malloc(sizeof(t_table));
	if (!tmp)
		return (-1);
	tmp->dinner_over = false;
	tmp->all_threads_ready = false;
	tmp->forks = NULL;
	tmp->philos = NULL;
	tmp->camera = 0;
	tmp->full_philo_count = 0;
	tmp->max_meal_per_philo = 0;
	tmp->philo_count = 0;
	tmp->running_threads_count = 0;
	tmp->start_time = 0;
	tmp->dinner_over = false;
	handle_mutex(&tmp->print_mutex, INIT);
	handle_mutex(&tmp->table_mutex, INIT);
	*table = tmp;
	return (0);
}

static void	assign_forks(t_table *table, t_philo *philo)
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

int	init_forks(t_table *table)
{
	t_fork	**forks;
	t_fork	*fork;
	int		i;

	forks = (t_fork **)malloc(sizeof(t_fork *) * table->philo_count);
	if (!forks)
		return (-1);
	i = -1;
	while (++i < table->philo_count)
	{
		fork = (t_fork *)malloc(sizeof(t_fork));
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
