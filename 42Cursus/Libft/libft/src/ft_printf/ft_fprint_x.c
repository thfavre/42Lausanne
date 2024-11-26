/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:21:02 by berard            #+#    #+#             */
/*   Updated: 2024/11/26 18:36:11 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countn_x(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != '\0')
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_fprint_x(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		ft_fprint_x(n / 16, fd);
		ft_fprint_x(n % 16, fd);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), fd);
		else
			ft_putchar_fd((n - 10 + 'a'), fd);
	}
	len = ft_countn_x(n);
	return (len);
}
