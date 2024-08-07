/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:08:29 by dabouab           #+#    #+#             */
/*   Updated: 2024/08/07 15:31:26 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*new_philo(int num, int last_meal)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo *));
	if (!new)
		return (NULL);
	new->num = num;
	new->last_meal = last_meal;
	new->num_meal = 0;
	new->state = 't';
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	philo_add_back(t_philo **philos, t_philo *new)
{
	t_philo	*first;
	t_philo	*last;

	if (!new || !philos)
		return ;
	first = *philos;
	last = *philos;
	if (!last)
	{
		*philos = new;
		return ;
	}
	while (last->next != first)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->next = first;
}

void	clear_philos(t_philo **philos)
{
	t_philo	*temp;

	while (*philos)
	{
		temp = (*philos)->next;
		free(*philos);
		*philos = temp;
	}
	free(philos);
}
