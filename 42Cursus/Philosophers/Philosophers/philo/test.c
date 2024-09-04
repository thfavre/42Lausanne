# include <stdio.h>
# include <pthread.h>

void	*someThreadFun(void *arg)
{
	int i = 0;
	while (1)
		printf("In someThreadFun\n");
	return NULL;
}

// example using threads
int main()
{
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, someThreadFun, NULL);
	while (1)
		printf("After Thread\n");
	pthread_join(thread_id, NULL); // The pthread_join function waits for the specified thread to terminate before continuing with the execution of the calling thread.
}
