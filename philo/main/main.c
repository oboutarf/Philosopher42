/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:17:51 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/02 03:35:11 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_gen	*general;

	if ((ac != 5 && ac != 6) || check_num(av, ac))
		return (ft_putstr(WRONG_INPUT), 1);
	if (ft_atoi(av[1]) == 1)
		return (one_philo(ft_atoi(av[2])), 0);
	general = init_simulation(av);
	launch_simulation(general);
	set_free(general);
	return (0);
}
