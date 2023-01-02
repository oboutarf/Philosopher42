/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:04:08 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/02 03:34:03 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	one_philo(int time_to_die)
{
	printf("0\t1 has taken a fork\n");
	ft_usleep(time_to_die);
	printf("%d\t1 is dead\n", time_to_die);
}

void	*philo_life(void *p)
{
	t_gen	*general;
	t_philo	*philo;

	philo = (t_philo *)p;
	general = (t_gen *)philo->general;
	pthread_mutex_lock(&(general->write));
	pthread_mutex_unlock(&(general->write));
	if (philo-> id % 2 == 0)
		ft_usleep(general->tt_e / 2);
	while (!is_dead(philo))
	{
		take_forks(philo, general);
		eating(philo, general);
		if (check_round_of_table(general))
			return (NULL);
		sleeping(philo, general);
		thinking(philo, general);
	}
	return (NULL);
}

void	launch_simulation(t_gen *general)
{
	int		i;

	i = -1;
	pthread_mutex_lock(&(general->write));
	while (++i < general->n_philo)
	{
		general->philo->last_eat = current_time();
		pthread_create(&(general->philo[i].thread),
			NULL, &philo_life, (void *)&(general->philo[i]));
	}
	general->start_process_time = current_time();
	pthread_mutex_unlock(&(general->write));
	usleep((general->tt_d) * 1000);
	while (dead_check(general) == 0)
		usleep(5000);
	join_threads(general);
}
