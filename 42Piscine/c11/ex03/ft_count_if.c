/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:17:25 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/22 13:28:45 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i++]) != 0)
			count++;
	}
	return (count);
}
/*
#include <stdio.h>
int f(char *s){
	int i = 0;
	while (s[i])
		if (s[i++] == 'z')
			return 0;
	return 1;
}
int main()
{
	char *t[] = {"azzzzzzbc", "def", "ghij"};
	printf("%d ", ft_count_if(t, 3, f));
}
*/
