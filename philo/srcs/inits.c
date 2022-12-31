/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 00:48:20 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 23:36:22 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_gen *general)
{
	int		i;

	i = -1;
	general->is_dead = 0;
	while (++i < general->n_philo)
	{
		general->philo[i].id = i + 1;
		general->philo[i].n_tt_e = 0;
		general->philo[i].lfork = i;
		general->philo[i].rfork = i + 1;
		if (i + 1 == general->n_philo)
			general->philo[i].rfork = 0;
		general->philo[i].general = general;
	}
}

void	*init_mutex(t_gen *general)
{
	int		i;

	i = -1;
	general->forks = malloc(sizeof(pthread_mutex_t) * general->n_philo);
	if (!general->forks)
		return (set_free(general), NULL);
	while (++i < general->n_philo)
		pthread_mutex_init(&(general->forks[i]), NULL);
	pthread_mutex_init(&(general->write), NULL);
	pthread_mutex_init(&(general->check), NULL);
	return (NULL);
}

t_gen	*init_simulation(char **av)
{
	t_gen	*general;

	general = malloc(sizeof(t_gen));
	if (!general)
		return (set_free(general), NULL);
	general->n_philo = ft_atoi(av[1]);
	general->tt_d = ft_atoi(av[2]);
	general->tt_e = ft_atoi(av[3]);
	general->tt_s = ft_atoi(av[4]);
	general->philo = malloc(sizeof(t_philo) * general->n_philo);
	if (!general->philo)
		return (NULL);
	if (av[5])
		general->number_philo_eat = ft_atoi(av[5]);
	general->is_dead = 0;
	init_mutex(general);
	init_philos(general);
	return (general);
}
