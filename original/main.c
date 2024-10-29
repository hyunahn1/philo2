#include "philo.h"

static int  init_mutex(t_data *data)
{
    int i;

    i = 0;
    data->death = 0;
    data->fork = 0;
    data->death = malloc(sizeof(pthread_mutex_t));
    if (!data->death)
    {
        ft_error("Error : Mutex allocate error", data, 0, 0);
        return (-1);
    }
    data->fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
    if (!data->fork)
    {
        ft_error("Error : Mutex allocate error", data, 0, 0);
        return (-1);
    }
    if (pthread_mutex_init(data->death, NULL) == -1)
    {
        ft_error("Error : Mutex init error", data, 0, 0);
        return (-1);
    }
    while (++i < data->n_philo)
    {
		if (pthread_mutex_init(&data->fork[i], NULL) == -1)
        {
			ft_error("Error\nMutex init failed\n", data, 0, 0);
            return (-1);
        }
    }
	return (0);
}
static int  init_data(t_data *data, char **argv)
{
    int     i;

    i = -1;
    data->n_philo = ft_atoi(argv[1]);
    data->t_die = ft_atoi(argv[2]);
    data->t_eat = ft_atoi(argv[3]);
    data->t_sleep = ft_atoi(argv[4]);
    data->max_eat = -2;
    data->how_eat = 0;
    data->t_start = 0;
    data->philo_ready = 0;
    if (argv[5])
    {
        data->how_eat = 1;
        data->max_eat = ft_atoi(argv[5]);
    }
    data->t_over = 0;
    if (data->n_philo > 0)
    i = init_mutex(data);
    return (i || data->n_philo <= 0 || data->t_die <= 0 || data->t_eat <= 0
        || data->t_sleep <= 0 || data->max_eat == 0);
}


int main(int argc, char **argv)
{
    t_data   data;

    if (argc != 5 && argc != 6)
    {
        ft_error ("Error: wrong arguments", &data, 0, 0);
        return (1);
    }
    if (init_data(&data, argv))
    {
        ft_error ("Error: wrong init", &data, 0, 0);
        return (1);
    }
    if (play_philo(&data))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}