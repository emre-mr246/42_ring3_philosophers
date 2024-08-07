/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:58:49 by emgul             #+#    #+#             */
/*   Updated: 2024/08/07 16:10:48 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"
#include "../../lib/libft/inc/libft.h"

t_table *init_table()
{
	t_table *table;

	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	if (!table)
		return (NULL);
	return (table);	
}