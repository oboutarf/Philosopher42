/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:04:08 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 00:39:43 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(philo->general->forks[philo->rfork]));
	pthread_mutex_lock(&(philo->general->write));
	forks_messages(philo, " has taken left fork\n");
	pthread_mutex_unlock(&(philo->general->write));
	pthread_mutex_lock(&(philo->general->forks[philo->lfork]));
	pthread_mutex_lock(&(philo->general->write));
	forks_messages(philo, " has taken right fork\n");
	pthread_mutex_unlock(&(philo->general->write));
	(void)general;
}

void	eat(t_philo *philo, t_gen *general)
{
	eat_messages(philo, " is eating\n");
	usleep(10000);
	pthread_mutex_unlock(&(philo->general->forks[philo->lfork]));
	pthread_mutex_unlock(&(philo->general->forks[philo->rfork]));
	(void)general;
}

void    *philo_life(void *p)
{
	t_gen	*general;
	t_philo	*philo;

	philo = (t_philo *)p;
	general = (t_gen *)philo->general;
	usleep(1000);
	while (1)
	{
		take_forks(philo, general);
		eat(philo, general);
		usleep(10000);
	}
	return (NULL);
}


void	launch_simulation(t_gen *general)
{
	int		i;

	i = -1;
	while (++i < general->n_philo)
		pthread_create(&(general->philo[i].thread), NULL, &philo_life, &(general->philo[i]));
	dead_check(general);
}