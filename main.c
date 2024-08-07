/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:35:57 by dabouab           #+#    #+#             */
/*   Updated: 2024/08/07 16:15:40 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av, t_args *args)
{
	if (ac < 5)
		return (clear("Not enough arguments"), EXIT_FAILURE);
	if (ac > 6)
		return (clear("Too many arguments"), EXIT_FAILURE);
	args->philo_num = ft_atoi(av[1]);
	args->die_time = ft_atoi(av[2]);
	args->eat_time = ft_atoi(av[3]);
	args->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		args->meal_num = ft_atoi(av[5]);
	else
		args->meal_num = -1;
	return (EXIT_SUCCESS);
}

int	initialize(t_args *args, t_philo **philos, t_fork **forks)
{
	int 						i;
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	if (args->philo_num < 1)
		return (clear("No philosophers", philos, forks), EXIT_FAILURE);
	i = 1;
	while (i <= args->philo_num)
	{
		philo_add_back(philos, new_philo(i, timestamp.tv_usec));
		fork_add_back(philos, new_fork(i));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	**philos;
	t_fork	**forks;

	if (check_args(ac, av, &args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philos = malloc(sizeof(t_philo **));
	forks = malloc(sizeof(t_fork **));
	if (!philos || !forks)
		return (clear("Malloc error", philos, forks), EXIT_FAILURE);
	if (initialize(&args, philos, forks) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (clear(NULL, philos, forks), EXIT_SUCCESS);
}
