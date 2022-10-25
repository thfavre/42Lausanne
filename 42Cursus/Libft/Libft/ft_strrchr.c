/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:12:36 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/25 16:14:22 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*save;

	i = 0;
	save = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			save = (char *)(s + i);
		i++;
	}
	if (c == '\0')
		save = (char *)(s + i);
	return (save);
}

// #include <stdio.h>
// int main()
// {printf("%s\n", ft_strrchr("aBcdecfc", 'c'));}