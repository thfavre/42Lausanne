/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:15:44 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/10 13:37:32 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*smod;

	i = 0;
	smod = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (smod == NULL)
		return (NULL);
	while (s[i])
	{
		smod[i] = (*f)(i, s[i]);
		i++;
	}
	smod[i] = 0;
	return (smod);
}
