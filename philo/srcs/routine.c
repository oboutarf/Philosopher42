/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:04:08 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 22:15:00 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *philo_life(void *p)
{
	t_gen	*general;
	t_philo	*philo;

	philo = (t_philo *)p;
	general = (t_gen *)philo->general;
	general->died = 0;
	philo->last_eat = general->start_process_time;
	// if (philo->id % 2 == 0)
	// 	usleep(general->tt_e * 1000);
	while (is_dead(philo, general) == 0)
	{
		take_forks(philo, general);
		eating(philo, general);
		sleeping(philo, general);
		thinking(philo, general);
	}
	return (NULL);
}

void	launch_simulation(t_gen *general)
{
	int		i;

	i = -1;
	general->start_process_time = current_time();
	while (++i < general->n_philo)
	{
		general->philo[i].last_eat = general->start_process_time;
		pthread_create(&(general->philo[i].thread), NULL, &philo_life, (void *)&(general->philo[i]));
	}
	dead_check(general);
	join_threads(general);
}
