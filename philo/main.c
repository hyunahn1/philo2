/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:55:48 by hyunahn           #+#    #+#             */
/*   Updated: 2024/10/30 13:55:50 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	p;

	if ((argc != 5 && argc != 6) || init_data(&p, argv))
		return (ft_error("Error: invalid arguments\n", &p, 0, 1));
	if (play_philo(&p))
		return (1);
	return (0);
}
