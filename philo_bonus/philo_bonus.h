/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:54:05 by emgul             #+#    #+#             */
/*   Updated: 2024/09/10 15:07:44 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
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
	TAKE_A_FORK,
	DIED
}						t_philo_status;

typedef struct s_philo
{
	t_table				*table;
	pthread_t			thread_id;
	sem_t				*philo_sem;
	int					id;
	long				meals_counter;
	long				last_meal_time;
	bool				is_full;
}						t_philo;

typedef struct s_table
{
	t_philo				**philos;
	sem_t				*forks;
	sem_t				*table_sem;
	sem_t				*print_sem;
	sem_t				*second_fork_sem;
	pthread_t			camera;
	long				philo_count;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				max_meal_per_philo;
	long				start_time;
	long				running_threads_count;
	long				full_philo_count;
	long				ate_philo_count;
	bool				dinner_over;
	bool				all_threads_ready;
}						t_table;

// UTILS
void					err_arg(void);
long					ft_atol(const char *str);
int						ft_issign(char c);
int						ft_isdigit(char c);

size_t					ft_strlen(const char *str);

// CLEAN
void					clean(t_table *table);

// INPUT
int						handle_input(t_table *table, char **av);

// INIT
int						init_table(t_table **table);
int						init_philos(t_table *table);
int						init_forks(t_table *table);

// GET AND SET
bool					get_bool(sem_t *sem, bool *value);
long					get_long(sem_t *sem, long *value);
void					set_bool(sem_t *sem, bool *dest, bool value);
void					set_long(sem_t *sem, long *dest, long value);
void					increase_long(sem_t *sem, long *value);

// TIME
void					usleep_lossless(long usec, t_table *table);
long					get_time_ms(void);

// THREADS
void					handle_thread(pthread_t *thread, void *(*func)(void *),
							void *data, t_operation opcode);
void					handle_sem(sem_t *sem, t_operation opcode);
sem_t					*create_sem(char *name, int value);

// DINNER
int						philosophers(t_table *table);

// DINNER UTILS
void					print_status(t_philo_status status, t_table *table,
							t_philo *philo);
void					lone_philo(t_table *table, t_philo *philo);
int						take_two_forks(t_table *table, t_philo *philo);
void					put_down_forks(t_table *table);

// MONITOR
void					*watch_routine(void *data);

#endif