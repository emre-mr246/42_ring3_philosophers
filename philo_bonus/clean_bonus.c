#include "philo_bonus.h"
#include "stdlib.h"
#include "error_bonus.h"

void	clean(t_table *table)
{
	int	i;

	i = 0;
	while (table->philos && i < table->philo_count)
	{
		if (table->philos[i]->philo_sem)
			handle_sem(table->philos[i]->philo_sem, DESTROY);
		if (table->philos[i])
			free(table->philos[i]);
		i++;
	}
	if (table->philos)
		free(table->philos);
	if (table->forks)
		handle_sem(table->forks, DESTROY);
	if (table->table_sem)
		handle_sem(table->table_sem, DESTROY);
	if (table->print_sem)
		handle_sem(table->print_sem, DESTROY);
	if (table->second_fork_sem)
		handle_sem(table->second_fork_sem, DESTROY);
	if (table)
		free(table);
}