/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:19:03 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 00:33:49 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		check_death_in_actions(t_gen *general)
{
	if (general->is_dead == 1)
		return (1);
	else
		return (0);
}

void	dead_check(t_gen *general)
{
	t_philo		*philo;
	int			i;

	general->is_dead = 0;
	philo = general->philo;
	while (general->is_dead != 1)
	{
		i = -1;
		while (++i < general->n_philo)
		{
			if ((current_time() - philo[i].last_eat) > general->tt_d)
			{
				general->is_dead = 1;
				pthread_mutex_lock(&(general->write));
				death_message(philo, " is dead\n");
				pthread_mutex_unlock(&(general->write));
				break ;
			}
		}
	}
}