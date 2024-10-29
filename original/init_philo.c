#include "philo.h"

int init_philo(t_data *data, t_philo *philo)
{
    int i;

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
        philo[i].left_fork = 0;
    }
    return (0);
}

int  init_thread(t_data *data, t_philo *philo)
{
    int i;

    i = -1;
    while (++i < data->n_philo)
    {
        philo[i].right_fork = philo[(i + 1) % data->n_philo].left_fork;
        if (pthread_create(&philo[i].thread, NULL,
                &thread_play, &philo[i]) == -1)
        {
            ft_error("Error : create pthread Failed", data, philo, 0);
            return (-1);
        }
    }
    i = -1;
    data->t_start = set_and_convert_to_milli();
    while (++i < data->n_philo)
    {
        philo[i].thread_start = data->t_start;
        philo[i].last_eat = data->t_start;
    }
    data->philo_ready = 1;
    return (0);
}