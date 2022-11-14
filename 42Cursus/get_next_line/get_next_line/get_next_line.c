#include <unistd.h>

char	*get_next_line(int fd)
{
	const int		BUFFER_SIZE = 4;
	static t_list	*stash;  // reserve
	char			*buffer;
	
	//1) find if there is a \n in the stash (and get the index)
	


}


int	get_(t_list *stash)
{
	int	i;

	while (stash->content)
	{
		if ((stash->content)[i] == '\n')
			return (i);
	i++;
	}
	return (i);
}


int	main()
{
	t_list l1;
	l1.


}
