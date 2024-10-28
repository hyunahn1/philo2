#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	ft_usleep(philo->data->t_sleep);
	print(philo, "is sleeping");
	print(philo, "is thinking");
}

void	ft_eat(t_philo *philo)
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

void    *thread_play(void *philo)
{
    t_philo *p;

    p = (void *)philo;
    while (!p->data->philo_ready)
        ;
    if (p->philo_id & 1)
        ft_usleep(p->data->t_eat * 0.9 + 1);
    while (!p->data->t_over)
    {
        ft_eat(p);
        ft_sleep(p);
    }
    return (0);
}