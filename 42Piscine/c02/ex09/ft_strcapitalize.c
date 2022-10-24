/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:40:15 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/04 02:58:19 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_char(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] <= 'Z') && (str[i] >= 'A'))
		{
			str[i] -= ('A' - 'a');
		}
		if ((str[i] <= 'z') && (str[i] >= 'a'))
		{
			if (i == 0 || (!is_char(str[i -1]) && !is_number(str[i -1])))
			{
				str[i] += ('A' - 'a');
			}
		}
		i++;
	}
	return (str);
}

//int main() {char str[] = "slt, comMent tu vAZs ? 42mots qe-deux; cQU+et+un"; 
//printf("/%s", ft_strcapitalize(str));}
