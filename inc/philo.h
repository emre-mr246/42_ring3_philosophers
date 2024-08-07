/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:54:05 by emgul             #+#    #+#             */
/*   Updated: 2024/08/07 16:13:01 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_table
{
	long philo_count;
	long time_to_die;
	long time_to_eat;
	long time_to_sleep;
	long max_meal_per_philo;
	long start_time;
}	t_table;

// UTILS
void err_arg(void);
long	ft_atol(const char *str);
int ft_issign(char c);

// CHECK INPUT
int handle_input(t_table *table, char **av);


#endif