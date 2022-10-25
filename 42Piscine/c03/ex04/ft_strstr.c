/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:57:33 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/25 16:12:15 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	n1;
	int	n2;

	if (*to_find == '\0')
		return (str);
	n1 = -1;
	while (*(str + ++n1))
	{
		if (*(str + n1) == *(to_find))
		{
			n2 = 0;
			while (*(str + n2 + n1))
			{
				if (*(str + n2 + n1) == *(to_find + n2))
				{
					n2++;
					if (*(to_find + n2) == '\0')
						return (str + n1);
					continue ;
				}
				break ;
			}
		}
	}
	return (NULL);
}

//int main(){printf("%s", ft_strstr("__Fi_FI_Find__OP", "Find"));}
