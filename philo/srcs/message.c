/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:11:09 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 23:18:43 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	death_message(t_philo *philo, char *message)
{
	ft_putnbr(time_stamp(philo->general->start_process_time, current_time()));
	ft_putchar('\t');
	ft_putnbr(philo->id);
	ft_putstr(message);
}

void	actions_logs(t_philo *philo, char *message)
{
	if (is_dead(philo))
		return ;
	ft_putnbr(time_stamp(philo->general->start_process_time, current_time()));
	ft_putchar('\t');
	ft_putnbr(philo->id);
	ft_putstr(message);
}