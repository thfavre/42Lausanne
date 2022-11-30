/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:58 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/10 12:13:07 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	count_nblen(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	check_sign(int *nb, int *sign)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*sign = -1;
	}
	else
		*sign = 1;
}

char	*ft_itoa(int nb)
{
	char	*nba;
	int		i;
	int		nblen;
	int		sign;

	nblen = count_nblen(nb);
	i = 0;
	if (nb == INT_MIN)
	{
		nba = ft_strdup("-2147483648");
		return (nba);
	}
	nba = ft_calloc(nblen + 1, sizeof(char));
	if (nba == NULL)
		return (NULL);
	check_sign(&nb, &sign);
	while (i < nblen)
	{
		nba[i++] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign < 0)
		nba[nblen - 1] = '-';
	return (ft_strrev(nba));
}
