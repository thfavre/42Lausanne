/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:42:57 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/26 16:26:40 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	size;

	size = ft_strlen(src) + 1;
	str = malloc(sizeof(*str) * size);
	if (str == NULL)
		return (NULL);
	return (ft_memcpy(str, src, size));
}
