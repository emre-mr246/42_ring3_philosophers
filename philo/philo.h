/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:54:05 by emgul             #+#    #+#             */
/*   Updated: 2024/09/10 15:06:06 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_table	t_table;

typedef enum e_operation
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN
}						t_operation;

typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED
}						t_philo_status;

typedef struct s_fork
{
	pthread_mutex_t		mutex;
	int					id;
}						t_fork;

typedef struct s_philo
{
	t_table				*table;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t			thread_id;
	pthread_mutex_t		philo_mutex;
	int					id;
	long				meals_counter;
	long				last_meal_time;
	bool				is_full;
}						t_philo;

typedef struct s_table
{
	t_philo				**philos;
	t_fork				**forks;
	pthread_t			camera;
	pthread_mutex_t		table_mutex;
	pthread_mutex_t		print_mutex;
	long				philo_count;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				max_meal_per_philo;
	long				start_time;
	long				running_threads_count;
	long				full_philo_count;
	bool				dinner_over;
	bool				all_threads_ready;
}						t_table;

// UTILS
void					err_arg(void);
long					ft_atol(const char *str);
int						ft_issign(char c);
size_t					ft_strlen(const char *str);

int						ft_isdigit(char c);

// CLEAN
void					clean(t_table *table);

// INPUT
int						handle_input(t_table *table, char **av);

// INIT
int						init_table(t_table **table);
int						init_philos(t_table *table);
int						init_forks(t_table *table);

// GET AND SET
bool					get_bool(pthread_mutex_t *mutex, bool *value);
long					get_long(pthread_mutex_t *mutex, long *value);
void					set_bool(pthread_mutex_t *mutex, bool *dest,
							bool value);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
void					increase_long(pthread_mutex_t *mutex, long *value);

// TIME
void					usleep_lossless(long usec, t_table *table);
long					get_time_ms(void);

// THREADS
void					handle_thread(pthread_t *thread, void *(*func)(void *),
							void *data, t_operation opcode);
void					handle_mutex(pthread_mutex_t *mutex,
							t_operation opcode);

// DINNER
int						philosophers(t_table *table);
void					thinking(t_table *table, t_philo *philo,
							bool dinner_started);

// DINNER UTILS
void					print_status(t_philo_status status, t_table *table,
							t_philo *philo);
void					wait_some_philos(t_table *table, t_philo *philo);
void					lone_philo(t_table *table, t_philo *philo);

// MONITOR
void					*watch_routine(void *data);

#endif