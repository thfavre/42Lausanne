#include <signal.h>
#include <unistd.h> //getpid function
#include <stdio.h>
#include <strings.h>
#include <sys/wait.h>

void modify_bit(int *nb, int pos, int bit_value)
{
    int mask = 1 << pos;
    *nb = (*nb & ~mask) | (bit_value << pos);
}

typedef struct s_letter
{
	unsigned int	current_bit;
	int				letter;
}		t_letter;

void	handle_sigusr(int sig)
{
	static t_letter	letter = {0, 0};

	if (sig == SIGUSR1)
		modify_bit(&letter.letter, letter.current_bit, 1);
		//(letter.letter >> letter.current_bit) = 1;
	else if (sig == SIGUSR2)
		modify_bit(&letter.letter, letter.current_bit, 0);
		//(letter.letter >> letter.current_bit) = 0;

	if (letter.current_bit == 8 - 1)
	{
		//printf("\nnb : %d\n", letter.letter);
		write(1, &letter.letter, 1);
		letter.current_bit = 0;
	}
	else
		letter.current_bit++;
	//printf("\ncurrent bit : %d\n", letter.current_bit);
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
		pause();
	}

	return (0);
}
