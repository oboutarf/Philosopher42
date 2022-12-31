/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:19:03 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 14:14:50 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	dead_check(t_gen *general)
{
	while (1)
	{
		if (general->is_dead == 1)
			break ;
	}
	join_threads(general);
}