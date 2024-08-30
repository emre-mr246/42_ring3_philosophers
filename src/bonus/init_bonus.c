/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:58:49 by emgul             #+#    #+#             */
/*   Updated: 2024/08/30 10:32:04 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo_bonus.h"
#include "../../lib/libft/inc/libft.h"

int	init_philos(t_table *table)
{
	t_philo	**philos;
	t_philo	*philo;
	int		i;

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
		philo->philo_sem = create_sem("philo_sem", 1);
		philos[i] = philo;
		i++;
	}
	table->philos = philos;
	return (0);
}

int	init_table(t_table **table)
{
	t_table	*tmp;

	tmp = (t_table *)ft_calloc(sizeof(t_table), 1);
	if (!tmp)
		return (-1);
	tmp->table_sem = create_sem("table_sem", 1);
	tmp->print_sem = create_sem("print_sem", 1);
	*table = tmp;
	return (0);
}