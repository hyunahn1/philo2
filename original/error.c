#include "philo.h"

void    ft_error(char *str, t_data *data, t_philo *philo, int flg)
{
    if (!flg)
    {
        if (data->death)
            free(data->death);
        if (data->fork)
            free(data->fork);
        if (philo)
            free(data);
    }
    printf("%s", str);
}