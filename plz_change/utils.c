/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:32:10 by mlazzare          #+#    #+#             */
/*   Updated: 2021/11/13 18:55:06 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str, t_data *data, t_philo *philo, int flg)
{
	if (flg)
	{
		if (data->death)
			free(data->death);
		if (data->fork)
			free(data->fork);
		if (philo)
			free(philo);
	}		
	return (printf("%s", str));
}

void	print_routine(t_philo *philo, char *action)
{
	pthread_mutex_lock(p->par->death);
	if (p->par->over)
	{
		pthread_mutex_unlock(p->par->death);
		return ;
	}
	printf("%ldms %d %s\n", time_now() - p->thread_start,
		p->id, action);
	pthread_mutex_unlock(p->par->death);
}
