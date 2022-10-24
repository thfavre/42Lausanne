/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:50:27 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/12 17:30:02 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}


//TODO faux 
int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	nbnumber;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (min < 0)
		nbnumber = abs(max) + abs(min);
	else
		nbnumber = max - min;
	tab = malloc(sizeof(int) * nbnumber);
	i = 0;
	while (min < max)
		tab[i++] = min++;
	*range = tab;
	return (i);
}
