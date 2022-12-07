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

enum e_state
{
	EATING,
	THINKING,
	SLEEPING,
	DEAD
}	;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_activity_times
{
	int				eat;
	int				sleep;
	int				die;

}					t_activities_times;

typedef struct s_philosopher
{
	int					id;
	enum e_state		state;
	struct timeval		start_time;
	struct timeval		last_eat_time;
	struct timeval		program_start_time;
	int					eat_count;
	t_activities_times	activities_times;
	pthread_mutex_t		*can_speak_mutex;

}						t_philosopher;

/*
** =============================================================================
** Functions
** =============================================================================
*/
//	philo.c
bool	isDead(t_philosopher *philosopher);
void	eat(t_philosopher *philosopher);
void	sleep_(t_philosopher *philosopher);
void	think(t_philosopher *philosopher);
void	*ft_philosopher(void *arg);
#endif
