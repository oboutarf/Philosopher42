/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:17:51 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/29 12:32:18 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/philosophers.h"

int		main(int ac, char **av)
{
	t_gen	*general;

	if ((ac != 5 && ac != 6) || check_num(av, ac))
		return (ft_putstr(WRONG_INPUT), 1);
	init_simulation(general);
	return (0);
}
