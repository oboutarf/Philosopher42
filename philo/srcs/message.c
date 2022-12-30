/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:11:09 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 00:25:00 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    forks_messages(t_philo *philo, char *message)
{
    ft_putstr(ft_itoa(philo->id));
    ft_putstr(message);
}

void    eat_messages(t_philo *philo, char *message)
{
    ft_putstr(ft_itoa(philo->id));
    ft_putstr(message);
}