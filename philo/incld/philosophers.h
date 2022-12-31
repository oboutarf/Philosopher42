/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:47:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/12/31 15:27:59 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
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
	long long			last_eat;
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
	int					number_philo_eat;
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
long long	time_stamp(long long start_time, long long actual_time);
long long 	 current_time(void);
// @ -------------------------- #Init ----------------------------- @ //
t_gen	*init_simulation(char **av);
void	*init_mutex(t_gen *general);
void	init_philos(t_gen *general);
// @ -------------------------- #Libft ---------------------------- @ //
void	ft_putstr(char *str);
void	ft_putchar(char c);
int     ft_atoi(char *str);
void	ft_putnbr(int n);
// @ ------------------------- #Parsing --------------------------- @ //
int     check_num(char **str, int nb);
// @ ------------------------- #Routine --------------------------- @ //
void	take_forks(t_philo *philo, t_gen *general);
void	sleeping(t_philo *philo, t_gen *general);
void	eating(t_philo *philo, t_gen *general);
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
void	thinking_message(t_philo *philo, char *message);
void    forks_messages(t_philo *philo, char *message);
void	sleep_messages(t_philo *philo, char *message);
void	death_message(t_philo *philo, char *message);
void    eat_messages(t_philo *philo, char *message);

#endif