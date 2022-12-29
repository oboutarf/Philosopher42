/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:27:31 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/29 23:29:30 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    print_state_after_init(t_gen *general)
{
    int     i;

    i = -1;
    while (++i < general->n_philo)
        printf("id: %d   lfork = %d  rfork = %d         %ld\n", general->philo[i].id, 
                general->philo[i].lfork, general->philo[i].rfork, general->philo[i].thread);
    
}
