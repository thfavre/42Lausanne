/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:53:01 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/22 18:18:32 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	add_buffer_to_stash(char *buffer, char **stash);
char	*create_line(char *stash);
void	clean_stash(char **stash);

char	*get_next_line(int fd)
{

	static char	*stash;  // reserve
	char		*buffer;
	char		*line;
	int			read_nbr;
	
	/*if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = 0;
		return (NULL);
	}*/
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		//free(stash);
		return (NULL);
	}
	read_nbr = 1;
	while (!ft_strchr(stash, '\n') && (read_nbr = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		if (add_buffer_to_stash(buffer, &stash) < 0)
		{

			//free(stash);
			//free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	if (read_nbr <= 0)
	{
		//free(stash);
		return (NULL);
	}
	line = create_line(stash);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	clean_stash(&stash);
	return (line);

}

int	add_buffer_to_stash(char *buffer, char **stash)
{
	int	stash_len;
	char	*new_stash;

	stash_len = ft_strlen(*stash);
	new_stash = malloc(sizeof(*new_stash) * (stash_len + ft_strlen(buffer) + 1)); // gestion erreur
	if (!new_stash)
		return (-1);
	if (*stash)
	{
		ft_strcpy(new_stash, *stash);
	}
	ft_strcpy(new_stash + stash_len, buffer);
	new_stash[stash_len + ft_strlen(buffer)] = '\0';
	*stash = new_stash;
	return (1);
}

char	*create_line(char *stash)
{
	int		line_len;
	char	*line;

	line_len = 0;
	while (stash[line_len] && stash[line_len] != '\n')
		line_len++;
	line = malloc(sizeof(*stash) * (line_len + 2)); // + 1??
	if (!line)
		return (NULL);
	line = ft_strncpy(line, stash, line_len);
	line[line_len + 1] = '\n';
	//printf("line : {}%s}\n", line);
	return (line);
}

void	clean_stash(char **stash)
{
	int		line_len;
	char	*new_stash;

	line_len = 0;
	while ((*stash)[line_len] && (*stash)[line_len] != '\n')
		line_len++;
	if ((*stash)[line_len] == '\n')
		line_len++;
	new_stash = malloc(sizeof(*new_stash) * (ft_strlen(*stash + line_len) + 1));
	new_stash = ft_strcpy(new_stash, *stash + line_len);
	new_stash[ft_strlen(*stash + line_len)] = '\0';
	//printf("#%s#", new_stash);
	free(*stash);
	*stash = new_stash;
}


#include <fcntl.h>
int	main()
{
	int	fd = open("file.txt", O_RDONLY);
	int i = 0;
	while (i++ < 15)
		printf("\nRES : |%s|\n", get_next_line(fd));
	//int i = 0;
	//while (i++ < 20)
	//	printf("->{%s}\n\n", get_next_line(fd));


}


