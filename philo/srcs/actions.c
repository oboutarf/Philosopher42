/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:21:06 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 00:50:56 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thinking(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	if (check_death_in_actions(general) == 1)
		return (pthread_mutex_unlock(&(general->write)), NULL);
	thinking_message(philo, " is thinking\n");
	pthread_mutex_unlock(&(general->write));
	usleep(1000 * (philo->general->tt_e));
	return (NULL);
}

void	*sleeping(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	if (check_death_in_actions(general) == 1)
		return (pthread_mutex_unlock(&(general->write)), NULL);
	sleep_messages(philo, " is sleeping\n");
	pthread_mutex_unlock(&(general->write));
	usleep(1000 * philo->general->tt_s);
	return (NULL);
}

void	*take_forks(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(philo->general->forks[philo->rfork]));
	pthread_mutex_lock(&(general->write));
	if (check_death_in_actions(general) == 1)
		return (pthread_mutex_unlock(&(general->write)),
			pthread_mutex_unlock(&(philo->general->forks[philo->rfork])), NULL);
	forks_messages(philo, " has taken his right fork\n");
	pthread_mutex_unlock(&(general->write));
	pthread_mutex_lock(&(philo->general->forks[philo->lfork]));
	pthread_mutex_lock(&(general->write));
	if (check_death_in_actions(general) == 1)
		return (pthread_mutex_unlock(&(general->write)),
			pthread_mutex_unlock(&(philo->general->forks[philo->rfork])),
				pthread_mutex_unlock(&(philo->general->forks[philo->lfork])), NULL);
	forks_messages(philo, " has taken his left fork\n");
	pthread_mutex_unlock(&(general->write));
	return (NULL);
}

void	*eating(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
		if (check_death_in_actions(general) == 1)
		return (pthread_mutex_unlock(&(general->write)),
			pthread_mutex_unlock(&(philo->general->forks[philo->rfork])),
				pthread_mutex_unlock(&(philo->general->forks[philo->lfork])), NULL);
	eat_messages(philo, " is eating\n");
	(philo->n_tt_e)++;
	pthread_mutex_unlock(&(general->write));
	usleep(1000 * philo->general->tt_e);
	philo->last_eat = current_time();
	pthread_mutex_unlock(&(philo->general->forks[philo->rfork]));
	pthread_mutex_unlock(&(philo->general->forks[philo->lfork]));
	return (NULL);
}
