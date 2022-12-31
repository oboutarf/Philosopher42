/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:21:06 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 18:22:50 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	thinking_message(philo, " is thinking\n");
	pthread_mutex_unlock(&(general->write));
	usleep(1000 * (philo->general->tt_e / 2));
}

void	sleeping(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	sleep_messages(philo, " is sleeping\n");
	pthread_mutex_unlock(&(general->write));
	usleep(1000 * philo->general->tt_s);
}

void	take_forks(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(philo->general->forks[philo->rfork]));
	pthread_mutex_lock(&(general->write));
	forks_messages(philo, " has taken his right fork\n");
	pthread_mutex_unlock(&(general->write));
	pthread_mutex_lock(&(philo->general->forks[philo->lfork]));
	pthread_mutex_lock(&(general->write));
	forks_messages(philo, " has taken his left fork\n");
	pthread_mutex_unlock(&(general->write));
}

void	eating(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	eat_messages(philo, " is eating\n");
	(philo->n_tt_e)++;
	pthread_mutex_unlock(&(general->write));
	usleep(1000 * philo->general->tt_e);
	philo->last_eat = time_stamp(general->start_process_time, current_time());
	pthread_mutex_unlock(&(philo->general->forks[philo->lfork]));
	pthread_mutex_unlock(&(philo->general->forks[philo->rfork]));
}