/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:47:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 00:25:20 by oboutarf         ###   ########.fr       */
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
	long long			time_since_tt_e;
	int					death_timer;
	int					id;
	int					lfork;
	int					rfork;
	int					n_tt_e;
	pthread_t			thread;
	struct s_gen		*general;
}						t_philo;

typedef struct	s_gen
{
	long long			start_process_time;
	int					n_philo_eat;
	int					is_dead;
	int					n_philo;
	int					tt_d;
	int					tt_e;
	int					tt_s;
	pthread_mutex_t		write;
	pthread_mutex_t		*forks;
    t_philo				*philo;
}						t_gen;
// @ --------------------------- #Time ---------------------------- @ //
long long 	 current_time(void);
// @ -------------------------- #Init ----------------------------- @ //
t_gen	*init_simulation(char **av);
void	*init_mutex(t_gen *general);
void	init_philos(t_gen *general);
// @ -------------------------- #Libft ---------------------------- @ //
void	ft_putstr(char *str);
void	ft_putchar(char c);
int     ft_atoi(char *str);
char	*ft_itoa(int n);
int		ft_nbrlen(int n);
// @ ------------------------- #Parsing --------------------------- @ //
int     check_num(char **str, int nb);
// @ ------------------------- #Routine --------------------------- @ //
void	launch_simulation(t_gen *general);
void    *philo_life(void *p);
// @ --------------------------- #Free ---------------------------- @ //
void	join_threads(t_gen *general);
void	free_forks(t_gen *general);
void    set_free(t_gen *general);
// @ -------------------------- #Print ---------------------------- @ //
void    print_state_after_init(t_gen *general);
// @ --------------------------- #Dead ---------------------------- @ //
void	dead_check(t_gen *general);
// @ ------------------------- #message --------------------------- @ //
void    forks_messages(t_philo *philo, char *message);
void    eat_messages(t_philo *philo, char *message);

#endif