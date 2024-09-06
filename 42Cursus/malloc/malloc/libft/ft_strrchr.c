/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:12:36 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/27 17:37:27 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			save = (char *)(s);
		s++;
	}
	if ((char)c == '\0')
		save = (char *)(s);
	return (save);
}
