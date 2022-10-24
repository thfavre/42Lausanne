/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:08:08 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/14 18:29:45 by thfavre          ###   ########.fr       */
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

int	*ft_range(int min, int max)
{
	int	*range;
	int	nbnumber;
	int	i;
	int	curr_number;

	if (min >= max)
		return (NULL);
	if (min < 0)
		nbnumber = abs(max) + abs(min);
	else
		nbnumber = max - min;
	range = malloc(sizeof(int) * nbnumber);
	curr_number = min;
	i = 0;
	while (curr_number < max)
	{
		range[i] = curr_number;
		curr_number++;
		i++;
	}
	return (range);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	int *range  = ft_range(atoi(argv[1]), atoi(argv[2]));

	int i = 0;
	while (1)
	{
		printf(" %d ", range[i]);
		
		if (range[i] == atoi(argv[2]) - 1)
			break ;
		i++;
	}
	return (0);
}
*/
