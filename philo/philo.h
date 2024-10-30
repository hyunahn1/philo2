/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:59:25 by hyunahn           #+#    #+#             */
/*   Updated: 2024/10/30 13:59:27 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_data
{
	int				n_philo;
	int				philo_ready;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_eat;
	int				how_eat;
	int				t_over;
	long int		t_start;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
}	t_data;

typedef struct s_philo
{
	int				philo_id;
	int				dead_flg;
	int				how_eaten;
	long int		thread_start;
	long int		last_eat;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

//static int	ft_isnumber(const char *s);
//static int	is_overflow(int sign);
int			ft_atoi(const char *str);

int			init_philo(t_data *data, t_philo *philo);
//static int	init_mutex(t_data *data);
int			init_data(t_data *p, char **argv);
int			init_thread(t_data *data, t_philo *philo);

//static int	has_eaten(t_philo philo, int i);
//static void	monitoring(t_data *data, t_philo *philo);
//static void	exit_thread(t_data *data, t_philo *philo);
int			play_philo(t_data *data);

int			print_die(t_philo *philo);
//static int	is_dead(t_philo *philo);
void		print_sleep(t_philo *philo);
void		print_eat(t_philo *philo);
void		*thread_play(void *philo);

long long	set_and_convert_to_milli(void);
void		ft_usleep(int ms);
int			ft_error(char *str, t_data *data, t_philo *philo, int flg);
void		print(t_philo *philo, char *action);

#endif
