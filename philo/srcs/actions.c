/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:21:06 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/02 03:27:10 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_philo *philo, t_gen *general)
{
	actions_logs(philo, " is thinking\n");
	(void)general;
}

void	sleeping(t_philo *philo, t_gen *general)
{
	actions_logs(philo, " is sleeping\n");
	ft_usleep(philo->general->tt_s);
	(void)general;
}

void	take_forks(t_philo *philo, t_gen *general)
{
	if (philo->id == general->n_philo)
		pthread_mutex_lock(&(philo->general->forks[philo->rfork]));
	else
		pthread_mutex_lock(&(philo->general->forks[philo->lfork]));
	actions_logs(philo, " has taken a fork\n");
	if (philo->id == general->n_philo)
		pthread_mutex_lock(&(philo->general->forks[philo->lfork]));
	else
		pthread_mutex_lock(&(philo->general->forks[philo->rfork]));
	actions_logs(philo, " has taken a fork\n");
}

void	eating(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->check_meal[philo->id - 1]));
	philo->last_eat = current_time();
	pthread_mutex_unlock(&(general->check_meal[philo->id - 1]));
	actions_logs(philo, " is eating\n");
	ft_usleep(philo->general->tt_e);
	if (philo->id == general->n_philo)
	{
		pthread_mutex_unlock(&(philo->general->forks[philo->rfork]));
		pthread_mutex_unlock(&(philo->general->forks[philo->lfork]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->general->forks[philo->lfork]));
		pthread_mutex_unlock(&(philo->general->forks[philo->rfork]));
	}
	(philo->n_tt_e)--;
	if (philo->n_tt_e == 0)
	{
		pthread_mutex_lock(&(general->check_rot));
		(general->round_of_table)++;
		pthread_mutex_unlock(&(general->check_rot));
	}
}
