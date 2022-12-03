#include  <features.h>
#include <signal.h>

#include <stdio.h>
#include <strings.h>

// Signal handler for SIGINT
void	sigint_handler(int signal)
{
	if (signal == SIGINT)
		printf("\nIntercepted SIGINT!\n");
}

void set_signal_action(void)
{
	// Declare the sigaction structure
	struct sigaction	act;

	// Set all of the structure's bits to 0 to avoid errors
	// relating to uninitialized variables...
	bzero(&act, sizeof(act));
	// Set the signal handler as the default action
	act.sa_handler = &sigint_handler;
	// Apply the action in the structure to the
	// SIGINT signal (ctrl-c)
	sigaction(SIGINT, &act, NULL);
}

int	main(void)
{
	// Change SIGINT's associated action
	set_signal_action();
	// Infinite loop to give us time to do ctrl-c
	// as much as we want!
	while(1)
		continue ;
	return (0);
}

