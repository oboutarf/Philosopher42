/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:19:03 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 23:21:59 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		is_dead(t_philo *philo)
{
	pthread_mutex_lock(&(philo->general->check_death));
	if (philo->general->is_dead == 1)
	{
		pthread_mutex_unlock(&(philo->general->check_death));
		return (1);
	}
	pthread_mutex_unlock(&(philo->general->check_death));
	return (0);
}

void dead_check(t_gen *general)
{
	t_philo *philo;
	int i;

	philo = general->philo;
	while (1)
	{
		i = -1;
		while (++i < general->n_philo)
		{
			pthread_mutex_lock(&(general->check_meal));
			if ((current_time() - philo[i].last_eat) >= (long)general->tt_d)
			{
				pthread_mutex_unlock(&(general->check_meal));
				pthread_mutex_lock(&(general->check_death));
				general->is_dead = 1;
				pthread_mutex_unlock(&(general->check_death));
				pthread_mutex_lock(&(general->write));
				death_message(philo, " is dead\n");
				pthread_mutex_unlock(&(general->write));
				return ;
			}
			pthread_mutex_unlock(&(general->check_meal));
			usleep(5);
		}
		usleep(20);
	}
}