/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:13:44 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/29 12:25:48 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     check_num(char **str, int nb)
{
    int     i[2];

    i[0] = 1;
    while (1)
    {
        i[1] = 0;
        while (str[i[0]][i[1]])
        {
            if (!(str[i[0]][i[1]] >= '0' && str[i[0]][i[1]] <= '9'))
                return (1);
            i[1]++;
        }
        if (i[0] + 1 == nb)
            return (0);
        i[0]++;
    }
}