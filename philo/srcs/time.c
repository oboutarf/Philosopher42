/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:31:23 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 00:09:13 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_sleep(long long time, t_gen *general)
{
	int		delta_time;

	delta_time = current_time();
	while (check_death_in_actions(general) != 1)
	{
		if (current_time() - delta_time >= time)
			break ;
		usleep(10);
	}
}

long long	time_stamp(long long start_time, long long actual_time)
{
	return (actual_time - start_time);
}

long long 	current_time(void)
{
	long long 				current_time;
	struct timeval 			tv;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time);
}
