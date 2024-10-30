/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:56:09 by hyunahn           #+#    #+#             */
/*   Updated: 2024/10/30 13:56:10 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_play(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (!p->data->philo_ready)
		;
	if (p->philo_id % 2 != 0)
		ft_usleep(p->data->t_eat / 2);
	while (!p->data->t_over)
	{
		print_eat(p);
		print_sleep(p);
	}
	return (NULL);
}
