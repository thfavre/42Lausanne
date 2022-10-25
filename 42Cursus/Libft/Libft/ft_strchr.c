/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:23:38 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/25 16:14:21 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] != c)
		return (NULL);
	return ((char *)(s + i));
}

//#include <stdio.h>
// int main() {printf("%s\n", ft_strchr("aBcdef", 'c'));}