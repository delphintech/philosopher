/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:59:06 by dabouab           #+#    #+#             */
/*   Updated: 2024/08/07 17:11:18 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pick_forks(t_philo *philo, t_fork **forks)
{
	struct timeval	timestamp;
	t_fork	*fork1;
	t_fork	*fork2;

	fork1 = get_fork(forks, philo->num);
	fork2 = fork1->prev;
	pthread_mutex_lock(&(fork1->mutex));
	pthread_mutex_lock(&(fork2->mutex));
	if (fork1->used == FALSE && fork2->used == FALSE)
	{
		fork1->used = TRUE;
		printf(YELLOW "%ld %d has taken a fork\n" RESET, timestamp.tv_usec, philo->num);
		fork2->used = TRUE;
		printf(YELLOW "%ld %d has taken a fork\n" RESET, timestamp.tv_usec, philo->num);
	}
}

void	check_death(t_philo *philo, int die_time)
{
	// Check the death of the philosopher
	// If he died, print the announce and clear + quit everything
}

void	philo_life(t_philo *philo, t_fork **forks, t_args args)
{
	while (philo->state != 'd')
	{
		if (philo->num_meal <= philo->next->num_meal && philo->num_meal <= philo->next->num_meal)
		{
			pick_forks(philo, forks);
			change_state(philo, 'e');
			usleep(args.eat_time);
			
		}
	}

}
