/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:19:03 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 22:23:46 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		is_dead(t_philo *philo, t_gen *general)
{
	if (philo->general->is_dead == 1)
	{
		if (general->died == 1)
			return (1);
		return (1);
	}
	return (0);
}

void	dead_check(t_gen *general)
{
	t_philo		*philo;
	int			i;

	philo = general->philo;
	while (general->is_dead != 1)
	{
		i = -1;
		while (++i < general->n_philo)
		{
			if ((current_time() - philo[i].last_eat) > general->tt_d)
			{
				pthread_mutex_lock(&(general->write));
				death_message(philo, general, " is dead\n");
				general->is_dead = 1;
				pthread_mutex_unlock(&(general->write));
				break ;
			}
			++i;
		}
	}
}