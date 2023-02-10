#ifndef PHILO_H
# define PHILO_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/
typedef struct s_fork
{
	pthread_mutex_t	mutex;
	bool			is_taken;
}					t_fork;

typedef struct s_stop
{
	pthread_mutex_t	mutex;
	int				finish_counter;
	bool			status;
}					t_stop;


typedef struct s_philo
{
	int					id;
	int					philos_numbers;
	//pthread_mutex_t		*stop_mutex;
	t_fork				*forks;
	int					last_eat_time;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	bool				is_dead;
	int					fork_in_hand_numbers;
	unsigned int		meal_number;
	int					meal_goal;
	t_stop				*stop;

}						t_philo;

/*
** =============================================================================
** Functions
** =============================================================================
*/
//	philo.c
void	*brain(void *args);
void	die(t_philo *philo);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	dream(t_philo *philo);
bool	should_stop(t_philo *philo);
//	utils.c
void	logs(char *msg, t_philo *philo);
int		get_time_in_ms();
#endif
