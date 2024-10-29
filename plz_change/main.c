/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:31:20 by mlazzare          #+#    #+#             */
/*   Updated: 2024/10/29 03:38:53 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		philo[i].philo_id = i;
		philo[i].dead_flg = 0;
		philo[i].how_eaten = 0;
		philo[i].thread_start = 0;
		philo[i].last_eat = 0;
		philo[i].data = data;
		philo[i].left_fork = &data->fork[i];
		philo[i].right_fork = 0;
	}
	return (0);
}

static int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->death = 0;
	data->fork = 0;
	data->death = malloc(sizeof(pthread_mutex_t));
	if (!data->death)
		return (ft_error("Error\nMutex death: malloc failed\n", data, 0, 1));
	data->fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->fork)
		return (ft_error("Error\nMutex fork: malloc failed\n", data, 0, 1));
	if (pthread_mutex_init(data->death, NULL) == -1)
		return (ft_error("Error\nMutex init failed\n", data, 0, 1));
	while (++i < data->n_philo)
		if (pthread_mutex_init(&data->fork[i], NULL) == -1)
			return (ft_error("Error\nMutex init failed\n", data, 0, 1));
	return (0);
}

static int	init_data(t_data *p, char **argv)
{
	int	mutex;

	mutex = -1;
	p->n_philo = ft_atoi(argv[1]);
	p->t_die = ft_atoi(argv[2]);
	p->t_eat = ft_atoi(argv[3]);
	p->t_sleep = ft_atoi(argv[4]);
	p->max_eat = -2;
	p->how_eat = 0;
	p->t_start = 0;
	p->philo_ready = 0;
	if (argv[5])
	{
		p->how_eat = 1;
		p->max_eat = ft_atoi(argv[5]);
	}
	p->t_over = 0;
	if (p->n_philo > 0)
		mutex = init_params_mutex(p);
	return (mutex || p->n_philo <= 0 || p->t_die <= 0 || p->t_eat <= 0
		|| p->t_sleep <= 0 || p->max_eat == 0);
}

int	main(int argc, char **argv)
{
	t_data	p;

	if ((argc != 5 && argc != 6) || init_data(&p, argv))
		return (ft_error("Error: invalid arguments\n", &p, 0, 1));
	if (play_philo(&p))
		return (1);
	return (0);
}
