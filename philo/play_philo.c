/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:55:56 by hyunahn           #+#    #+#             */
/*   Updated: 2024/10/30 13:55:57 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_dead(t_philo *philo)
{
	long int	now;

	pthread_mutex_lock(philo->data->death);
	now = set_and_convert_to_milli() - philo->last_eat;
	if (now >= philo->data->t_die)
	{
		pthread_mutex_unlock(philo->data->death);
		return (print_die(philo));
	}
	pthread_mutex_unlock(philo->data->death);
	return (0);
}

static int	has_eaten(t_philo philo, int i)
{
	if (philo.data->how_eat
		&& i == philo.data->n_philo - 1
		&& philo.how_eaten == philo.data->max_eat)
	{
		ft_usleep(300);
		return (1);
	}
	return (0);
}

static void	monitoring(t_data *data, t_philo *philo)
{
	int	i;

	while (!data->philo_ready)
		continue ;
	while (!data->t_over)
	{
		i = -1;
		while (++i < data->n_philo)
			if (is_dead(&philo[i]) || has_eaten(philo[i], i))
				data->t_over = 1;
	}
}

static void	exit_thread(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
		pthread_join(philo[i].thread, (void *)&philo[i]);
	pthread_mutex_destroy(data->death);
	pthread_mutex_destroy(data->fork);
	free(data->death);
	free(data->fork);
	free(philo);
}

int	play_philo(t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!philo || init_philo(data, philo))
		return (1);
	if (init_thread(data, philo))
		return (1);
	monitoring(data, philo);
	exit_thread(data, philo);
	return (0);
}
