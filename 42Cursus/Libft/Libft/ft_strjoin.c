/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:53:31 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 11:19:41 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = malloc(sizeof(*s) * (s1_len + s2_len + 1));
	if (s != NULL)
	{
		ft_memcpy(s, s1, s1_len);
		ft_memcpy(s + s1_len, s2, s2_len);
		s[s1_len + s2_len] = '\0';
	}
	return (s);
}
