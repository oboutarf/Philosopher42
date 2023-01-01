/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:19:03 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 18:48:50 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		is_dead(t_philo *philo)
{
	pthread_mutex_lock(&(philo->general->check));
	if (philo->general->is_dead == 1)
	{
		pthread_mutex_unlock(&(philo->general->check));
		return (1);
	}
	pthread_mutex_unlock(&(philo->general->check));
	return (0);
}

void dead_check(t_gen *general)
{
	t_philo *philo;
	long time;
	int i;

	philo = general->philo;
	while (1)
	{
		i = -1;
		while (++i < general->n_philo)
		{
			pthread_mutex_lock(&(general->check_meal));
			time = (current_time() - philo[i].last_eat);
			pthread_mutex_unlock(&(general->check_meal));
			if (time >= general->tt_d)
			{
				pthread_mutex_lock(&(general->check));
				general->is_dead = 1;
				pthread_mutex_unlock(&(general->check));
				pthread_mutex_lock(&(general->write));
				death_message(philo, " is dead\n");
				pthread_mutex_unlock(&(general->write));
				return ;
			}
		}
		ft_usleep(5);
	}
}