/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:48:44 by dabouab           #+#    #+#             */
/*   Updated: 2024/08/07 17:08:37 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clear(char *msg, t_philo **philos, t_fork **forks)
{
	if (philos)
		clear_philos(philos);
	if (forks)
		clear_forks(forks);
	if (msg)
		printf("%s\n", msg);
}

void	change_state(t_philo *philo, char state)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	philo->state = state;
	if (state == 't')
		printf(PURPLE "%ld %d is thinking\n" RESET, timestamp.tv_usec, philo->num);
	if (state == 'e')
		printf(GREEN "%ld %d is eating\n" RESET, timestamp.tv_usec, philo->num);
	if (state == 's')
		printf(BLUE "%ld %d is sleeping\n" RESET, timestamp.tv_usec, philo->num);
	if (state == 'd')
		printf(RED "%ld %d has died\n" RESET, timestamp.tv_usec, philo->num);
}
