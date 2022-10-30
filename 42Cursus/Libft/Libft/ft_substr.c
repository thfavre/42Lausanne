/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:41:35 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 04:41:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	
	i = 0;
	str = malloc(sizeof(*str) * (len + 1)); // for the \0? 
	// create the exact size for
	// test is start > len if s ?
	if (str != NULL)
	{
		while (s[start + i] && i < len)
			{
				str[i] = s[start + i];
				i++;
			}
		str[i] = '\0';
	}
	return (str);
}
