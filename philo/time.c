/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:56:25 by hyunahn           #+#    #+#             */
/*   Updated: 2024/10/30 13:56:26 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	set_and_convert_to_milli(void)
{
	struct timeval	value;

	gettimeofday(&value, NULL);
	return (value.tv_sec * 1000 + value.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = set_and_convert_to_milli();
	while (set_and_convert_to_milli() - time < ms)
		usleep(ms / 10);
}
