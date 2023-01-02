/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:47:55 by oboutarf          #+#    #+#             */
/*   Updated: 2023/01/02 03:39:40 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define WRONG_INPUT "Wrong arguments!\n"
// @ ----------------------- #Includes --------------------------- @ //
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
// @ ------------------------ #Structs --------------------------- @ //
typedef struct s_philo
{
	long long			last_eat;
	int					id;
	int					lfork;
	int					rfork;
	int					n_tt_e;
	pthread_t			thread;
	struct s_gen		*general;
}						t_philo;

typedef struct s_gen
{
	long long				start_process_time;
	int						number_philo_eat;
	int						round_of_table;
	int						is_dead;
	int						n_philo;
	int						tt_d;
	int						tt_e;
	int						tt_s;
	pthread_mutex_t			write;
	pthread_mutex_t			check_rot;
	pthread_mutex_t			check_death;
	pthread_mutex_t			*check_meal;
	pthread_mutex_t			*forks;
	t_philo					*philo;
}						t_gen;
// @ --------------------------- #Time ---------------------------- @ //
long long	time_stamp(long long start_time, long long actual_time);
long long	current_time(void);
void		ft_usleep(int ms);
// @ -------------------------- #Init ----------------------------- @ //
t_gen		*init_simulation(char **av);
void		*init_mutex(t_gen *general);
void		init_philos(t_gen *general);
// @ -------------------------- #Libft ---------------------------- @ //
void		ft_putstr(char *str);
void		ft_putchar(char c);
int			ft_atoi(char *str);
void		ft_putnbr(int n);
// @ ------------------------- #Parsing --------------------------- @ //
int			check_num(char **str, int nb);
// @ ------------------------- #Routine --------------------------- @ //
void		launch_simulation(t_gen *general);
void		one_philo(int time_to_die);
void		*philo_life(void *p);
// @ ------------------------- #Actions --------------------------- @ //
void		take_forks(t_philo *philo, t_gen *general);
void		sleeping(t_philo *philo, t_gen *general);
void		thinking(t_philo *philo, t_gen *general);
void		eating(t_philo *philo, t_gen *general);
// @ --------------------------- #Free ---------------------------- @ //
void		join_threads(t_gen *general);
void		free_forks(t_gen *general);
void		set_free(t_gen *general);
// @ --------------------------- #Dead ---------------------------- @ //
int			check_round_of_table(t_gen *general);
int			dead_check(t_gen *general);
int			is_dead(t_philo *philo);
// @ ------------------------- #Message --------------------------- @ //
void		death_message(t_philo *philo, char *message);
void		actions_logs(t_philo *philo, char *message);

#endif