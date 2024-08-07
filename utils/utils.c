/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:48:44 by dabouab           #+#    #+#             */
/*   Updated: 2024/08/07 16:08:22 by dabouab          ###   ########.fr       */
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

void	print_state(t_philo *philo)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	if (philo->state == 't')
		printf(PURPLE "%ld %d is thinking\n" RESET, timestamp.tv_usec, philo->num);
	if (philo->state == 'e')
		printf(GREEN "%ld %d is eating\n" RESET, timestamp.tv_usec, philo->num);
	if (philo->state == 's')
		printf(BLUE "%ld %d is sleeping\n" RESET, timestamp.tv_usec, philo->num);
	if (philo->state == 'd')
		printf(RED "%ld %d has died\n" RESET, timestamp.tv_usec, philo->num);
}
