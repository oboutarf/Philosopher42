/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:20:41 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/02 03:28:01 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_forks(t_gen *general)
{
	int		i;

	i = -1;
	while (++i < general->n_philo)
		pthread_mutex_destroy(&(general->forks[i]));
	i = -1;
	while (++i < general->n_philo)
		pthread_mutex_destroy(&(general->check_meal[i]));
	pthread_mutex_destroy(&(general->write));
	pthread_mutex_destroy(&(general->check_rot));
	pthread_mutex_destroy(&(general->check_death));
}

void	join_threads(t_gen *general)
{
	int		i;

	i = -1;
	while (++i < general->n_philo)
		pthread_join(general->philo[i].thread, NULL);
}

void	set_free(t_gen *general)
{
	destroy_forks(general);
	free(general->check_meal);
	free(general->forks);
	free(general->philo);
	free(general);
}
