/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:20:41 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/30 23:59:21 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_forks(t_gen *general)
{
	int		i;

	i = -1;
	while (++i < general->n_philo)
		pthread_mutex_destroy(&(general->forks[i]));
	pthread_mutex_destroy(&(general->write));
}

void	join_threads(t_gen *general)
{
	int		i;

	i =-1;
	while (++i < general->n_philo)
		pthread_join(general->philo[i].thread, NULL);
}

void    set_free(t_gen *general)
{
	destroy_forks(general);
	free(general->forks);
	free(general->philo);
	free(general);
}
