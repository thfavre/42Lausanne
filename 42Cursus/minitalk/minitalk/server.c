#include <signal.h>
#include <unistd.h> //getpid function
#include <stdio.h>
#include <strings.h>
#include <sys/wait.h>


void	handle_sigusr(int sig)
{
	static char	letter;
	if (sig == SIGUSR1)
		letter++;
	else if (sig == SIGUSR2)
	{
		write(1, &letter, 1);
		letter = 0;
	}
	//printf("cuurrent letter : %c \n", letter);
}

int	main(void)
{
	printf("Server PID : %d\n", getpid());

	struct sigaction sa1 = { 0 }; // create sigaction struct and set all to 0
	sa1.sa_flags = SA_RESTART;  // because we use scanf (otherwise delete this)
	sa1.sa_handler = &handle_sigusr;
	sigaction(SIGUSR1, &sa1, NULL);

	struct sigaction sa2 = { 0 }; // create sigaction struct and set all to 0
	sa2.sa_flags = SA_RESTART;  // because we use scanf (otherwise delete this)
	sa2.sa_handler = &handle_sigusr;

	sigaction(SIGUSR2, &sa2, NULL);

	while(1)
	{
		continue ;
	}

	return (0);
}
