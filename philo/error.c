/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:55:29 by hyunahn           #+#    #+#             */
/*   Updated: 2024/10/30 13:55:31 by hyunahn          ###   ########.fr       */
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
