/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:27:31 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/21 21:28:04 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "prototype.h"

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

int	power(int a, int b)
{
	int	res;
	int	n;

	if (b == 0)
		return (1);
	res = 1;
	n = b;
	while (n--)
		res *= a;
	return (res);
}

int	char_to_int(char c)
{
	return (c - '0');
}

int	ft_atoi(char *str)
{
	int	res;
	int	res_sign;

	res = 0;
	res_sign = 1;
	while (*str <= 32 || *str >= 126)
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			res_sign *= -1;
	while (is_num(*str))
	{
		res = res * 10 + char_to_int(*str);
		str++;
	}
	return (res_sign * res);
}
