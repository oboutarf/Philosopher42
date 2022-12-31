/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:04:08 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 15:31:25 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_philo *philo, t_gen *general)
{
	pthread_mutex_lock(&(general->write));
	thinking_message(philo, " is thinking");
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
	pthread_mutex_unlock(&(general->write));
	usleep(1000 * philo->general->tt_e);
	(philo->n_tt_e)++;
	philo->last_eat = time_stamp(general->start_process_time, current_time());
	pthread_mutex_unlock(&(philo->general->forks[philo->lfork]));
	pthread_mutex_unlock(&(philo->general->forks[philo->rfork]));
}

void    *philo_life(void *p)
{
	t_gen	*general;
	t_philo	*philo;

	philo = (t_philo *)p;
	general = (t_gen *)philo->general;
	if (philo->id % 2)
		usleep(((general->tt_d - (general->tt_e + general->tt_s)) / 2) * 1000);
	while (1)
	{
		take_forks(philo, general);
		eating(philo, general);
		sleeping(philo, general);
	}
	return (NULL);
}
// usleep(((general->tt_d - (general->tt_e + general->tt_s)) / 2) * 1000);


void	launch_simulation(t_gen *general)
{
	int		i;

	i = -1;
	while (++i < general->n_philo)
		pthread_create(&(general->philo[i].thread), NULL, &philo_life, (void *)&(general->philo[i]));
	dead_check(general);
}
// usleep(((general->tt_d - (general->tt_e + general->tt_s)) / 2) * 1000);