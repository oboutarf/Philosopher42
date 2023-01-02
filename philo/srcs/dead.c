/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:19:03 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/02 03:26:30 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_round_of_table(t_gen *general)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(general->check_rot));
	if (general->round_of_table == general->n_philo)
		i = 1;
	pthread_mutex_unlock(&(general->check_rot));
	return (i);
}

int	is_dead(t_philo *philo)
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

int	dead_check(t_gen *general)
{
	t_philo		*philo;
	int			i;

	philo = general->philo;
	i = -1;
	while (++i < general->n_philo)
	{
		pthread_mutex_lock(&(general->check_meal[i]));
		if ((current_time() - philo[i].last_eat) > (long)general->tt_d)
		{
			pthread_mutex_unlock(&(general->check_meal[i]));
			pthread_mutex_lock(&(general->check_death));
			general->is_dead = 1;
			pthread_mutex_unlock(&(general->check_death));
			pthread_mutex_lock(&(general->write));
			death_message(philo, " is dead\n");
			pthread_mutex_unlock(&(general->write));
			return (1);
		}
		pthread_mutex_unlock(&(general->check_meal[i]));
	}
	return (check_round_of_table(general));
}
