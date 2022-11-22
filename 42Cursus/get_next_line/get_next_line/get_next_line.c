#include "get_next_line.h"



char	*read_file(int fd, char *stash);
char	*create_line(char *stash);
char	*clean_stash(char *stash);

char	*get_next_line(int fd)
{

	static char	*stash;  // reserve
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = create_line(stash);
//	printf("Line : {%s} \n", line);
//	printf("Stash befome clean: {%s} \n", stash);
	stash = clean_stash(stash);
	
//	printf("Stash : {%s} \n", stash);
	return (line);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		read_nbr;
	char	*temp;
	if (!stash)
		stash = ft_calloc(1, 1);

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));	
	read_nbr = 1;
	while (!ft_strchr(stash, '\n') && read_nbr > 0)
	{
		read_nbr = read(fd, buffer, BUFFER_SIZE);
		if (read_nbr == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[read_nbr] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		//printf("\n|%s|\n", stash);
		//if (ft_strchr(buffer, '\n'))
		//	break ;
	}
	free(buffer);
	//printf("->|%s|\n", stash);
	return (stash);
}

char	*create_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash[0])
		return (NULL);

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(*line)); // + 1??
	//line = ft_strncpy(line, stash, line_len);
	// line = buffer
	
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	//TODO
	//printf("*%d*\n", line[]);
	if (stash[i] && stash[i] == '\n')
		line[i] = '\n';
	//line[line_len + 0] = '\n';
	//line[line_len + 1] = '\0';
	
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (stash[i] && stash[i] != '\n')
		i++;
	// if eol == \0 return NULL
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (stash[i])
		line[j++] = stash[i++];
	line[j] = '\0';
	free(stash);
	return (line);
}

/*
#include <fcntl.h>
int	main()
{
	int	fd = open("file2.txt", O_RDWR);
	int i = 0;
	while (i++ < 19)
		//get_next_line(fd);
		printf("RES : |%s|\n", get_next_line(fd));
	//int i = 0;
	//while (i++ < 20)
	//	printf("->{%s}\n\n", get_next_line(fd));
}*/
