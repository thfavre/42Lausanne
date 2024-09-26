/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:01:13 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/28 14:41:32 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *stash);
char	*create_line(char *stash);
char	*clean_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = create_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
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
	}
	free(buffer);
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
	line = ft_calloc(i + 2, sizeof(*line));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;
	int		stash_len;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	stash_len = 0;
	while (stash[stash_len])
		stash_len++;
	new_stash = malloc((stash_len - i + 1) * sizeof(char));
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

// # include <stdio.h>
// #include <fcntl.h>
// int	main()
// {
// 	int	fd = open("file2.txt", O_RDWR);
// 	int i = 0;
// 	while (i++ < 19)
// 		//get_next_line(fd);
// 		printf("RES : |%s|\n", get_next_line(fd));
// }
