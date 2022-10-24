/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:36:11 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/10 16:48:44 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_str_compare(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

// swap memory address of str1 with str2  
void	ft_switch(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_sort_params(char **argv)
{
	int	i;
	int	restart;

	restart = 1;
	i = 0;
	while (argv[i + 1])
	{
		if (ft_str_compare(argv[i], argv[i + 1]) > 0)
		{
			ft_switch(&argv[i], &argv[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{	
	if (argc == 1)
		return (0);
	ft_sort_params(&argv[1]);
	while (*(++argv))
	{
		ft_putstr(*argv);
		write(1, "\n", 1);
	}
	return (0);
}
