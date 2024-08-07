/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:54:05 by emgul             #+#    #+#             */
/*   Updated: 2024/08/07 22:24:46 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdbool.h>
#include <pthread.h>

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY
}	t_opcode;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int 	id;
}	t_fork;

typedef struct s_philo
{
	int id;
	int meals_counter;
	t_fork *left_fork;
	t_fork *right_fork;
	bool 	is_full;
	long last_meal_time;
	pthread_t thread_id;
}	t_philo;

typedef struct s_table
{
	long philo_count;
	long time_to_die;
	long time_to_eat;
	long time_to_sleep;
	long max_meal_per_philo;
	long start_time;
	bool end_simulation;
	t_fork *forks;
	t_philo *philos;
}	t_table;

// UTILS
void err_arg(void);
long	ft_atol(const char *str);
int ft_issign(char c);

// CHECK INPUT
int handle_input(t_table *table, char **av);

void handle_mutex(pthread_mutex_t *mutex, t_opcode opcode);


#endif