/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:57:30 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/25 17:13:53 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
	char    *srcdup;
	size_t	i;

	srcdup = ft_strdup((char *)src);
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = srcdup[i];
		i++;
	}
	return (dst);
}
int main(){}