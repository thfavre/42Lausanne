#include <sys/time.h>
enum e_state
{
	EATING,
	THINKING,
	SLEEPING;
}

typedef struct s_philosopher
{
	int				id;
	enum e_state	state;
	struct timeval	start_time;
	int				eat_count;

}					t_philosopher;
