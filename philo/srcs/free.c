/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:20:41 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/29 23:23:59 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_forks(t_gen *general)
{
	int		i;

	i = -1;
	while (++i < general->n_philo)
		pthread_mutex_destroy(&(general->forks[i]));
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
	join_threads(general);
	destroy_forks(general);
	free(general->forks);
	free(general->philo);
	free(general);
}