#include "philo.h"

void	print_die(t_philo *philo)
{
	print(philo, "died");
	philo->data->t_over = 1;
	philo->dead_flg = 1;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	is_dead(t_philo *philo)
{
	long int	now;

	pthread_mutex_lock(philo->data->death);
	now = set_and_convert_to_milli() - philo->last_eat;
	if (now >= philo->data->t_die)
	{
		pthread_mutex_unlock(philo->data->death);
		print_die(philo);
        return (1);
	}
	pthread_mutex_unlock(philo->data->death);
	return (0);
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