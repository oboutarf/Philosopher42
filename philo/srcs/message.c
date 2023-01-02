/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:11:09 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/02 03:29:57 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	death_message(t_philo *philo, char *message)
{
	long long	timestamp;

	timestamp = (time_stamp(philo->general->start_process_time,
				current_time()));
	printf("%lld\t%d%s", timestamp, philo->id, message);
}

void	actions_logs(t_philo *philo, char *message)
{
	long long	timestamp;

	timestamp = (time_stamp(philo->general->start_process_time,
				current_time()));
	if (is_dead(philo))
		return ;
	printf("%lld\t%d%s", timestamp, philo->id, message);
}
