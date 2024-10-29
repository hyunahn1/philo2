#include "philo.h"

static int  has_eaten(t_philo philo, int i)
{
    if (philo.data->how_eat
        && i == philo.data->n_philo - 1
        && philo.how_eaten == philo.data->max_eat)
        {
        ft_usleep(500);
        return (1);
        }
    return (0);
}

static void monitoring(t_data *data, t_philo *philo)
{
    int i;

    while (!data->philo_ready)
        ;
    while (!data->t_over)
    {
        i = -1;
        while (++i < data->n_philo)
        {
            if ((is_dead(&philo[i])) || has_eaten(philo[i], i))
                data->t_over = 1;
        }
    }
}

static int  init_thread(t_data *data, t_philo *philo)
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

static void exit_thread(t_data *data, t_philo *philo)
{
    int i;

    i = -1;
    while (++i < data->n_philo)
        pthread_join(philo[i].thread, (void *)&philo[i]);
    pthread_mutex_destroy(data->death);
    pthread_mutex_destroy(data->fork);
    free(data->death);
    free(data->fork);
    free(philo);
}
int play_philo(t_data *data)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo) * data->n_philo);
    if (!philo || init_philo(data, philo))
        return (-1);
    if (init_thread(data, philo))
        return (-1);
    monitoring(data, philo);
    exit_thread(data, philo);
    return (0);
}