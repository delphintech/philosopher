/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:08:29 by dabouab           #+#    #+#             */
/*   Updated: 2024/08/07 16:27:37 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*new_fork(int num)
{
	t_fork	*new;

	new = malloc(sizeof(t_fork *));
	if (!new)
		return (NULL);
	pthread_mutex_init(&(new->mutex), NULL);
	new->num = num;
	new->used = FALSE;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	fork_add_back(t_fork **forks, t_fork *new)
{
	t_fork	*first;
	t_fork	*last;

	if (!new || !forks)
		return ;
	first = *forks;
	last = *forks;
	if (!last)
	{
		*forks = new;
		return ;
	}
	while (last->next != first)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->next = first;
}

t_fork	*get_fork(t_fork **forks, int num)
{
	t_fork	*temp;

	temp = *forks;
	while (temp)
	{
		if (temp->num == num)
			retrun (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	clear_forks(t_fork **forks)
{
	t_fork	*temp;

	while (*forks)
	{
		temp = (*forks)->next;
		pthread_mutex_destroy(&((*forks)->mutex));
		free(*forks);
		*forks = temp;
	}
	free(forks);
}
