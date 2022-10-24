/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:06:52 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/22 11:20:59 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*
//COMMENT THAT :
void add3AndPrint(int i) {   printf(" %d ", i + 3);   }

int main()
{
	int tab[] = {1, 2, 3, 10};
	ft_foreach(tab, 4, &add3AndPrint);
}
*/
