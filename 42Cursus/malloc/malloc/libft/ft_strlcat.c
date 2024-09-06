/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:11:34 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/30 13:04:16 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		total_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < ft_strlen(dst))
		total_len = ft_strlen(src) + dstsize;
	else
		total_len = ft_strlen(src) + ft_strlen(dst);
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (total_len);
}
