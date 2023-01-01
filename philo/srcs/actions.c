/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:21:06 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 18:45:29 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void thinking(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	thinking_message(philo, " is thinking\n");
	pthread_mutex_unlock(&(general->write));
}

void sleeping(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	sleep_messages(philo, " is sleeping\n");
	pthread_mutex_unlock(&(general->write));
	ft_usleep(philo->general->tt_s);
}

void take_forks(t_philo *philo, t_gen *general)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&(philo->general->forks[philo->rfork]));
	else
		pthread_mutex_lock(&(philo->general->forks[philo->lfork]));
	pthread_mutex_lock(&(general->write));
	forks_messages(philo, " has taken a fork\n");
	pthread_mutex_unlock(&(general->write));
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&(philo->general->forks[philo->lfork]));
	else
		pthread_mutex_lock(&(philo->general->forks[philo->rfork]));
	pthread_mutex_lock(&(general->write));
	forks_messages(philo, " has taken a fork\n");
	pthread_mutex_unlock(&(general->write));
}

void eating(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->check_meal));
	philo->last_eat = current_time();
	pthread_mutex_unlock(&(general->check_meal));
	(philo->n_tt_e)++;
	pthread_mutex_lock(&(general->write));
	eat_messages(philo, " is eating\n");
	pthread_mutex_unlock(&(general->write));
	ft_usleep(philo->general->tt_e);
	if (philo->id % 2 == 0) {
		pthread_mutex_unlock(&(philo->general->forks[philo->rfork]));
		pthread_mutex_unlock(&(philo->general->forks[philo->lfork]));
	}
	else {
		pthread_mutex_unlock(&(philo->general->forks[philo->lfork]));
		pthread_mutex_unlock(&(philo->general->forks[philo->rfork]));
	}
}
