//#include  <features.h>
#include <signal.h>
#include <unistd.h> //getpid function
#include <stdio.h>
#include <strings.h>
#include <sys/wait.h>

// // Signal handler for SIGINT
// void	sigint_handler(int signal)
// {
// 	if (signal == SIGINT)
// 		write(STDOUT_FILENO, "\nIntercepted SIGINT!\n", 23);
// }

// void set_signal_action(void)
// {
// 	// Declare the sigaction structure
// 	struct sigaction	act;

// 	// Set all of the structure's bits to 0 to avoid errors
// 	// relating to uninitialized variables...
// 	bzero(&act, sizeof(act));
// 	// Set the signal handler as the default action
// 	act.sa_handler = &sigint_handler;
// 	// Apply the action in the structure to the
// 	// SIGINT signal (ctrl-c)
// 	sigaction(SIGINT, &act, NULL);
// }

void	handle_sigusr1(int sig)
{
	printf(" (Hint) Remember that multiplication is repetitive addition\n");
}

int	main(void)
{
	int pid = fork();
	if (pid == -1)
		return (-1);
	printf("\n1) %d\n", getppid());
	if (pid == 0) // the child process
	{
		sleep(5);
		kill(getppid(), SIGUSR1); // it is the parent process id
	}
	else // parent process
	{
		struct sigaction sa = { 0 }; // create sigaction struct and set all to 0
		sa.sa_flags = SA_RESTART;  // because we use scanf (otherwise delete this)
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);

		int x;
		printf("What is the result of 3 x 5 : ");
		scanf("%d", &x);
		write(1, "rep", 3);
		if (x == 15)
			printf("Right");
		else
			printf("Wrong");
	}
	wait(NULL); // wait for the child process to finish
	// // Change SIGINT's associated action
	// set_signal_action();
	// // Infinite loop to give us time to do ctrl-c
	// // as much as we want!
	// while(1)
	// 	{
	// 		printf("pid %d\n", getpid());
	// 		continue ;
	// 	}
	return (0);
}

