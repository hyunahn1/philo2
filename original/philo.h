#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
    int             philo_id;    //철학자 고유 ID
    int             dead_flg;   //죽음 플래그
    int				how_eaten;    //철학자가 몇 번 식사를 했는지
	long int		thread_start; //스레드 스타트가 언제인지
	long int		last_eat;       //철학자가 마지막으로 식사한 시각
	pthread_t		thread;   //각각의 철학자가 독립적으로 관리하기 위해
	pthread_mutex_t	*left_fork;        //왼쪽 포크 뮤텍스
	pthread_mutex_t	*right_fork;        //오른쪽 포크 뮤텍스
	struct s_data		*data;       // 전체 파라미터를 참조
}	t_philo;

typedef struct s_data
{
	int				n_philo;        //철학자의 수
	int				philo_ready;      //철학자들이 모두 준비되었는지
	int				t_die;        //철학자가 죽기까지 걸리는 시간
	int				t_eat;        //철학자가 식사를 하는 데 걸리는 시간
	int				t_sleep;        //철학자가 잠에 드는데 걸리는 시간
	int				max_eat;   //각 철학자가 수행할 최대 식사 횟수
	int				how_eat; //철학자들이 얼마나 식사했는지 플래그
	int				t_over;       //시뮬레이션 종료여부 플래그
	long int		t_start;      //시뮬레이션 시작된 시간 플래그
	pthread_mutex_t	*death;     //죽음 상태 보호 뮤택스
	pthread_mutex_t	*fork;      //전체 포크 상태 뮤택스
}	t_data;

long long	set_and_convert_to_milli(void);
void	ft_usleep(int ms);
void    ft_error(char *str, t_data *data, t_philo *philo, int flg);
int	ft_atoi(const char *str);
int init_philo(t_data *data, t_philo *philo);
static int  init_thread(t_data *data, t_philo *philo);
static int  init_mutex(t_data *data);
static int  init_data(t_data *data, char **argv);
int	is_dead(t_philo *philo);
static int  has_eaten(t_philo philo, int i);
static void monitoring(t_data *data, t_philo *philo);
static void exit_thread(t_data *data, t_philo *philo);
int play_philo(t_data *data);
void	print_die(t_philo *philo);
void	print(t_philo *philo, char *action);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
void    *thread_play(void *philo);


#endif