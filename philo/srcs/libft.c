/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:57:14 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 00:19:12 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

int		ft_nbrlen(int n)
{
	int				size;
	unsigned int	nb;

	size = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		nb = n * -1;
		size = 1;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;

	i = ft_nbrlen(n);
	str = malloc(i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

int     ft_atoi(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb);
}

