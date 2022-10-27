/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:11:34 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/27 18:15:23 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);

	j = 0;
	while (src[j] &&  dstlen+j < dstsize - 1)//i + j - 1 < dstsize)
	{
		dst[dstlen + j] = src[j];
		j++;
	}
	if (!(dstsize == 0 && dstlen > dstsize))
		dst[dstlen + j] = 0;
	return (dstlen + srclen);
}
