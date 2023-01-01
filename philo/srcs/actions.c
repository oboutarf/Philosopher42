/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:21:06 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 22:19:33 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void thinking(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	actions_logs(philo, " is thinking\n");
	pthread_mutex_unlock(&(general->write));
}

void sleeping(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	actions_logs(philo, " is sleeping\n");
	pthread_mutex_unlock(&(general->write));
	ft_usleep(philo->general->tt_s);
}

void take_forks(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(philo->general->forks[philo->lfork]));
	pthread_mutex_lock(&(general->write));
	philo->fork_stamp = current_time();
	actions_logs(philo, " has taken a fork\n");
	pthread_mutex_unlock(&(general->write));
	pthread_mutex_lock(&(philo->general->forks[philo->rfork]));
	pthread_mutex_lock(&(general->write));
	philo->fork_stamp = current_time();
	actions_logs(philo, " has taken a fork\n");
	pthread_mutex_unlock(&(general->write));
}

void eating(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->check_meal));
	philo->last_eat = current_time();
	(philo->n_tt_e)++;
	pthread_mutex_unlock(&(general->check_meal));
	pthread_mutex_lock(&(general->write));	
	actions_logs(philo, " is eating\n");
	pthread_mutex_unlock(&(general->write));
	ft_usleep(philo->general->tt_e);
	pthread_mutex_unlock(&(philo->general->forks[philo->rfork]));
	pthread_mutex_unlock(&(philo->general->forks[philo->lfork]));
}
