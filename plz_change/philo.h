/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:32:05 by mlazzare          #+#    #+#             */
/*   Updated: 2021/11/13 17:58:05 by mlazzare         ###   ########.fr       */
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
	int			n_philo;	//num;
	int			philo_ready;	//ready;
	int			t_die;	//t2d;
	int			t_eat;	//t2e;
	int			t_sleep;	//t2s;
	int			max_eat;	//max_iter;
	int			how_eat;	//check_meal;
	int			t_over;	//over;
	long int	t_start;	//start;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
}	t_data;

typedef struct s_philo
{
	int				philo_id;	//id;
	int				dead_flg;	//dead;
	int				how_eaten;	//iter_num;
	long int		thread_start;	//thread_start;
	long int		last_eat;	//meal;
	pthread_t		thread;	//life_tid;
	pthread_mutex_t	*left_fork;	//*lf;
	pthread_mutex_t	*right_fork;	//*rf;
	t_data		*data;	//*par;
}	t_philo;


#endif
