/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:31:23 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/01 18:14:28 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	ft_usleep(long int duration, t_philo *philo)
// {
// 	long int	start;
// 	long int	current;

// 	(void)philo;
// 	start = -1;
// 	start = current_time();
// 	if (start == -1)
// 		return (1);
// 	else
// 	{
// 		while (1)
// 		{
// 			current = current_time() - start;
// 			if (current >= duration)
// 				break ;
// 			if (duration - current > 1000)
// 				usleep(100);
// 			else
// 				usleep((duration - current) / 10);
// 			// if (is_dead(phil))
// 			// 	return (1);
// 		}
// 	}
// 	return (0);
// }

void	ft_usleep(int ms)
{
	long int	time;

	time = current_time();
	while (current_time() - time < ms)
		usleep(50);
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
