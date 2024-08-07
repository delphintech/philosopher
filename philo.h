/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:36:22 by dabouab           #+#    #+#             */
/*   Updated: 2024/08/07 17:08:59 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

# define RESET "\x1b[0m"
# define BLUE "\x1b[34m"
# define RED "\x1b[31m"
# define PURPLE "\x1b[35m"
# define GREEN "\x1b[32m"
# define BLACK "\x1b[30m"
# define YELLOW "\x1b[33m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"

typedef struct s_args
{
	int	philo_num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	meal_num;
}	t_args;

typedef struct s_philo
{
	pthread_t	*thread;
	int			num;
	int			last_meal;
	int			num_meal;
	char		state;
	t_philo		*prev;
	t_philo		*next;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int							num;
	int							used;
	t_fork					*prev;
	t_fork					*next;
}	t_fork;

// ft_atoi
	int	ft_atoi(const char *nptr);

// utils
	void	clear(char *msg, t_philo **philos, t_fork **forks);
	void	change_state(t_philo *philo, char state);

// philo_struct
t_philo		*new_philo(int num, int last_meal);
void			philo_add_back(t_philo **philos, t_philo *new);
void			clear_philos(t_philo **philos);

// fork_struct
t_philo	*new_fork(int num);
void	fork_add_back(t_fork **forks, t_fork *new);
t_fork	*get_fork(t_fork **forks, int num);
void	clear_forks(t_fork **forks);

#endif
