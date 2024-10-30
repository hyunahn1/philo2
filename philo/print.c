/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:56:19 by hyunahn           #+#    #+#             */
/*   Updated: 2024/10/30 13:56:20 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_die(t_philo *philo)
{
	print(philo, "died");
	philo->data->t_over = 1;
	philo->dead_flg = 1;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

void	print_sleep(t_philo *philo)
{
	ft_usleep(philo->data->t_sleep);
	print(philo, "is sleeping");
	print(philo, "is thinking");
}

void	print_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print(philo, "has taken a fork");
	philo->last_eat = set_and_convert_to_milli();
	ft_usleep(philo->data->t_eat);
	print(philo, "is eating");
	philo->how_eaten++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	print(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->data->death);
	if (philo->data->t_over)
	{
		pthread_mutex_unlock(philo->data->death);
		return ;
	}
	printf("%lld %d %s\n", set_and_convert_to_milli() - philo->thread_start,
		philo->philo_id, action);
	pthread_mutex_unlock(philo->data->death);
}
