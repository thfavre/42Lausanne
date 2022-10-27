/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:45:37 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/27 14:01:31 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	str_num_size(char *str)
{
	int	size;

	size = 0;
	while (is_num(*str))
	{
		size++;
		str++;
	}
	return (size);
}

int	char_to_int(char c)
{
	return (c - '0');
}

int	isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	ft_atoi(const char *str)
{
	int	res;
	int	res_sign;

	res = 0;
	res_sign = 1;
	while (isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			res_sign *= -1;
		str++;
	}
	while (is_num(*str))
	{
		res *= 10;
		res += char_to_int(*str);
		str++;
	}
	return (res_sign * res);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main() {char str[]="\t \n +508"; 
printf("%i\n", ft_atoi(str)); 
printf("%i", atoi(str));}
*/