/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:14:54 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/22 21:42:23 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	res = malloc(length * sizeof(int));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		res[i] = f(tab[i]);
	return (res);
}
/*
#include <stdio.h>
int rd(int i) { return i + 3;}
int main()
{
	int a[] = {1, 2, 3};
	int *b = ft_map(a, 3, &rd);
	printf(" %i ", b[0]);
}
*/
