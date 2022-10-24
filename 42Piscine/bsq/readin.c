/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:41:01 by jchapell          #+#    #+#             */
/*   Updated: 2022/09/21 23:30:18 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "prototype.h"

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	result = malloc(sizeof (*result) * (len + 1));
	if (result == NULL)
		return (NULL);
	if (result == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*read_stdin(void)
{
	char	*parsed;
	char	*tmp;
	char	buffer[1];
	int		i;

	parsed = malloc(sizeof(char));
	if (parsed == NULL)
		return (NULL);
	i = 0;
	while (read(0, &buffer, sizeof(buffer)) > 0)
	{
		tmp = ft_strdup(parsed);
		free(parsed);
		parsed = ft_strdup(tmp);
		parsed[i] = buffer[0];
		free(tmp);
		i++;
	}
	return (parsed);
}
