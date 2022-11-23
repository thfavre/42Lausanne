#include "get_next_line.h"

int	is_line_in_stash(t_list *stash);
int	add_buffer_to_stash(t_list **stash, int fd);
int	get_line_len(t_list *stash);
char	*create_line(t_list *stash, int line_len);
void	clean_stash(t_list *stash);

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;  // reserve
	int		line_len;
	char	*line;
	int		add_buffer_output;
	// 1) check if a '\n' is in the stash (can only in the first one if any)
	//if (stash != NULL)
	if (!is_line_in_stash(stash))
	{
		// 2) if TRUE : skip this step 
		//		add a buffer to the stash while the buffer does not contain a '\n' (or fd is finished)
		//add_buffer_to_stash(&stash, fd);
		while (add_buffer_to_stash(&stash, fd) == 0)
		{
			add_buffer_output = add_buffer_to_stash(&stash, fd);
			//printf("a : %d\n", add_buffer_output);
			if (add_buffer_output == -1)
				return (NULL);
			if (add_buffer_output == 1)
				break ;
		}
	}
	printf("s : '%s'\n", stash->content);
	//if (stash->content[0] == 0)
	//	return (NULL);
	// 3) count the size of the line
	line_len = get_line_len(stash);
	// 4) create with malloc the string containing the line
	line = create_line(stash, line_len);
	// 5) clear all the stash except the last one if he contain a '\n' 
	clean_stash(stash);
	return (line);
}

int	is_line_in_stash(t_list *stash)
{
	int	i;
	char	*stash_content;

	if (stash == NULL)
		return (0);
	i = 0;
	stash_content = stash->content;
	while (stash_content[i])
		if (stash_content[i++] == '\n')
			return (1);
	return (0);
}

int	add_buffer_to_stash(t_list **stash, int fd)
{
	char	*buffer;
	int		read_output;
	int		i;

	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	//check malloc 
	read_output = read(fd, buffer, BUFFER_SIZE);
	if (read_output == -1)
		return (-1); // error
	if (read_output == 0)
		return (-1); // nothing to read
	buffer[read_output] = '\0';
	ft_lstadd_back(stash, ft_lstnew(buffer));
	i = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			return (1);
	return (0);
}

int	get_line_len(t_list *stash)
{
	int	len;
	int	i;

	len = 0;
	while (stash)
	{
		i = 0;
		while ((stash->content)[i])
		{
			if ((stash->content)[i] == '\n')
				return (len);
			len++;
			i++;
		}
		stash = stash->next;
	}
	return (-1);
}

char	*create_line(t_list *stash, int line_len)
{
	char	*line;
	int		i;
	int		j;

	line = malloc(sizeof(*line) * (line_len + 1));
	
	i = 0;
	while (stash)
	{
		j = 0;
		while ((stash->content)[j])
		{
			if ((stash->content)[j] == '\n')
			{
				line[i] = '\0';
				return (line);
			}
			line[i] = (stash->content)[j];
			i++;
			j++;

		}
		stash = stash->next;
	}
	return (line);
}

void	clean_stash(t_list *stash)
{
	/*
	t_list *new_stash = ft_lstnew(" NEW ");
	*stash = *new_stash;
	*/
	t_list	*last;
	int		i;
	int		j;
	int		len;
	char	*str;
	t_list	*stash_ptr;

	stash_ptr = stash;
	last = ft_lstlast(stash);
	i = 0;
	while ((last->content)[i] && (last->content)[i] != '\n')
		i++;
	i++;
	len = 0;
	while ((last->content)[i + len])
		len++;
	printf("len : %d", len);
	//if (len > 0)
	//{
		str = malloc(sizeof(*str) * (len + 1));
		j = 0;
		while (j < len)
		{
			str[j] = (last->content)[i + j];
			j++;
		}
		str[j] = '\0';
	//}
	
	// last is next
	while (stash)
	{
		last = (stash)->next;
		free(stash->content);
		//ft_lstdelone(*lst, del);
		stash = last;
	}
	free(stash);
	//free(*lst);
	//*lst = NULL;	

	//if (len > 0)
		*stash_ptr = *ft_lstnew(str);


	/*
	t_list	*new_stash;
	char	*new_stash_content;
	int		i;
	int		j;
	char	*str;
	int		new_stash_len;
	t_list	*next;

	t_list *last = ft_lstlast(*stash);
	i = 0;
	while ((last->content)[i] != '\n')
		i++;
	//new_stash_content = last->content + i;
	new_stash_len = 0;
	j = 0;
	while ((last->content)[i + j++])
		new_stash_len++;
	new_stash
	new_stash = ft_lstnew(last->content + i + 1);

	while ((*stash))
	{
		next = (*stash)->next;
		free((*stash)->content);
		free(*stash);
		*stash = next;
	}
	stash = &new_stash;

	while (str[i])
	{
		lnew_stash_len++;
		i++;
	}
	new_stash_content 





	t_list	*next;
	while (*stash)
	{
		next = (*stash)->next;
		if (next->content != NULL)
		{
			free((*stash)->content);
			free(*stash);
			*stash = next;
		}
		else
		{
			
		}
	}
	*/
}

#include <fcntl.h>
int	main()
{
	int	fd = open("file.txt", O_RDONLY);
	int i = 0;
	while (i++ < 20)
		printf("->{%s}\n\n", get_next_line(fd));


}

