/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:45:37 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/01 17:24:14 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	char_to_int(char c)
{
	return (c - '0');
}

static int	ft_isspace(char c)
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
	while (ft_isspace(*str))
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