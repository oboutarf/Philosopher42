/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:47:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/29 12:43:54 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOPSOPHERS_H
# define WRONG_INPUT "Wrong arguments!\n"
// @ ----------------------- #Includes --------------------------- @ //
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// @ ------------------------ #Structs --------------------------- @ //
typedef struct	s_gen
{
	int			n_philo_eat;
	int			n_philo;
	int			tt_d;
	int			tt_e;
	int			tt_s
    t_philo		*philo;
}				t_gen;

typedef struct 	s_philo
{
	int			sandglass;
	int			id;
	
	struct t_gen	t_gen;
}				t_philo;
// @ -------------------------- #Init ----------------------------- @ //

// @ -------------------------- #Libft ---------------------------- @ //
void	ft_putstr(char *str);
int     ft_atoi(char *str);
void	ft_putchar(char c);
// @ ------------------------- #Parsing --------------------------- @ //
int     check_num(char **str, int nb);

#endif