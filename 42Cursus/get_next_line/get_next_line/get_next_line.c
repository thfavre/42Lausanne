
#include <unistd.h>

char	*get_next_line(int fd)
{
	const int	BUFFER_SIZE = 4;
	static char *stash;  // reserve
	char	*buffer;
	
	stash = "";
	
	// remove the previously added sentense from the buffer
	j = strchr(stash, '\n');
	if (j != NULL)
		stash += j;

	// read only if there any sentense in the stash
	while (ft_strchr(stash, '\n') == NULL && read(fd, buffer, BUFFER_SIZE) > 0 )
	{
		read(fd, buffer, BUFFER_SIZE);

		// add the buffer to the stash
		strlcat(stash, buffer, strlen(stash) + BUFFER_SIZE);
	}
	j = strchr(stash, '\n');
	if (j == NULL)
		return (stash);


	return (substr(stash, 0, j))

	i = 0;
}


int	main()
{

}
