/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:31:31 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/12 03:28:03 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		strlen;
	int		i;

	strlen = 0;
	while (src[strlen++])
		;
	str = malloc(sizeof(str) * strlen);
	if (str == NULL)
		return (0);
	i = -1;
	while (++i < strlen)
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
/*
int	main(int argc, char **argv){
	char *t  = ft_strdup("te  st");
	printf("%s", t);}
*/
