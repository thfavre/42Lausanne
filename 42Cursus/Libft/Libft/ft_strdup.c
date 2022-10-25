/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:42:57 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/25 17:09:57 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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