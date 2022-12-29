/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:47:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/29 16:38:25 by oboutarf         ###   ########.fr       */
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
typedef struct 	s_philo
{
	int				sandglass;
	int				id;
	int				lfork;
	int				rfork;
	pthread_t		thread;
	struct s_gen	*general;
}					t_philo;

typedef struct	s_gen
{
	int					n_philo_eat;
	int					n_philo;
	int					tt_d;
	int					tt_e;
	int					tt_s;
	pthread_mutex_t		*forks;
    t_philo				*philo;
}						t_gen;
// @ -------------------------- #Init ----------------------------- @ //
t_gen	*init_simulation(char **av);
void	init_philos(t_gen *general);
// @ -------------------------- #Libft ---------------------------- @ //
void	ft_putstr(char *str);
int     ft_atoi(char *str);
void	ft_putchar(char c);
// @ ------------------------- #Parsing --------------------------- @ //
int     check_num(char **str, int nb);
// @ ------------------------- #Routine --------------------------- @ //
void    *philo_life(void *general);

#endif