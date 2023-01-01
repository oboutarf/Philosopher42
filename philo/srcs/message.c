/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:11:09 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 18:30:45 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    forks_messages(t_philo *philo, char *message)
{
	if (is_dead(philo) == 1)
		return ;
	ft_putnbr(time_stamp(philo->general->start_process_time, current_time()));
	ft_putchar('\t');
    ft_putnbr(philo->id);
    ft_putstr(message);
}

void	thinking_message(t_philo *philo, char *message)
{
	if (is_dead(philo) == 1)
		return ;
	ft_putnbr(time_stamp(philo->general->start_process_time, current_time()));
	ft_putchar('\t');
	ft_putnbr(philo->id);
	ft_putstr(message);
}

void	death_message(t_philo *philo, char *message)
{
	ft_putnbr(time_stamp(philo->general->start_process_time, current_time()));
	ft_putchar('\t');
	ft_putnbr(philo->id);
	ft_putstr(message);
}

void	sleep_messages(t_philo *philo, char *message)
{
	if (is_dead(philo) == 1)
		return ;
	ft_putnbr(time_stamp(philo->general->start_process_time, current_time()));
	ft_putchar('\t');
	ft_putnbr(philo->id);
	ft_putstr(message);
}

void    eat_messages(t_philo *philo, char *message)
{
	if (is_dead(philo) == 1)
		return ;
	ft_putnbr(time_stamp(philo->general->start_process_time, current_time()));
	ft_putchar('\t');
    ft_putnbr(philo->id);
    ft_putstr(message);
}