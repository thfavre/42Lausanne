#include <signal.h>
#include <unistd.h> //getpid function
#include <stdio.h>
#include <strings.h>
#include <sys/wait.h>

char letter;

void	handle_sigusr1(int sig)
{
	letter++;
	//printf("cuurrent letter : %c \n", letter);
}

void	handle_sigusr2(int sig)
{
	write(1, &letter, 1);
	//write(1, "\t", 1);
	//printf("cuurrent letter : %c \n", letter);
	letter = 0;
	//printf(" Message catched! \n");
}

int	main(void)
{
	letter = 0;
	printf("Server PID : %d\n", getpid());

	struct sigaction sa1 = { 0 }; // create sigaction struct and set all to 0
	sa1.sa_flags = SA_RESTART;  // because we use scanf (otherwise delete this)
	sa1.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa1, NULL);

	struct sigaction sa2 = { 0 }; // create sigaction struct and set all to 0
	sa2.sa_flags = SA_RESTART;  // because we use scanf (otherwise delete this)
	sa2.sa_handler = &handle_sigusr2;

	sigaction(SIGUSR2, &sa2, NULL);

	while(1)
	{
		continue ;
	}

	return (0);
}
