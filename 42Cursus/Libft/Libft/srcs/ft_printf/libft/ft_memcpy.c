/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:29:25 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/07 17:16:33 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*desti;
	char			*srci;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	desti = (char *)dest;
	srci = (char *)src;
	while (i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	dest = desti;
	return (dest);
}
