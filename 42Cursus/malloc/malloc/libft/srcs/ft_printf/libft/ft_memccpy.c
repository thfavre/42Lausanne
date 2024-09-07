/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:03 by ybensegh          #+#    #+#             */
/*   Updated: 2022/10/24 14:36:51 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*desti;
	char			*srci;

	i = 0;
	desti = (char *)dest;
	srci = (char *)src;
	while (i < n)
	{
		desti[i] = srci[i];
		if (desti[i] == c)
		{
			dest = desti;
			i++;
			return (dest + i);
		}
		i++;
	}
	dest = desti;
	return (dest);
}
