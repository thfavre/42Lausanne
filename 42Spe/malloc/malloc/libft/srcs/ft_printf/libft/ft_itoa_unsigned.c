/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:58 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/18 11:07:31 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	count_nblen_unsigned(unsigned int nb)
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

char	*ft_itoa_unsigned(unsigned int nb)
{
	char	*nba;
	int		i;
	int		nblen;

	nblen = count_nblen_unsigned(nb);
	i = 0;
	nba = ft_calloc(nblen + 1, sizeof(char));
	if (nba == NULL)
		return (NULL);
	while (i < nblen)
	{
		nba[i++] = nb % 10 + '0';
		nb /= 10;
	}
	return (ft_strrev(nba));
}
