/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:19:03 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 18:26:08 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	dead_check(t_gen *general)
{
	int			i;

	while (1)
	{
		i = -1;
		while (++i < general->n_philo)
		{
			printf("LOOP\n");
			if ((general->start_process_time - general->philo[i].last_eat) > general->tt_d)
			{
				death_message(general->philo, " is dead\n");
				general->is_dead = 1;
				break ;
			}
		}
		if (general->is_dead == 1)
			break ;
	}
	printf("END-LOOP\n");
	
}