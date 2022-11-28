/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:49:01 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/01 01:02:26 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	screen(const char *big, const char *little, unsigned int *it)
{
	while (little[it[1]])
	{
		if (!(big[it[0]++] == little[it[1]++]))
		{
			it[1]--;
			return (0);
		}
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	it[3];

	it[0] = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[it[0]] && it[0] < len)
	{
		it[1] = 0;
		if (big[it[0]] == little[it[1]++])
		{
			it[2] = it[0]++;
			screen(big, little, it);
			if (!little[it[1]] && (it[0] <= len))
				return ((char *)big + it[2]);
			it[0] = it[2];
		}
		it[0]++;
	}
	return (NULL);
}
