/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:25:54 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/22 13:16:29 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i++]) != 0)
			return (1);
	}
	return (0);
}

/*
int doesStrContainZ(char *str)
{
	int i = 0; 
	while (str[i])
	{
		if (str[i] == 'z')
			return 1;
		i++;
	}
	return 0;
}

int main()
{
	char *a[] = {"burp blup", "Machines should work. People should think.", NULL};
	printf("%i", ft_any(a, &doesStrContainZ));
}*/
