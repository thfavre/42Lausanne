/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:45:45 by berard            #+#    #+#             */
/*   Updated: 2024/11/26 18:35:51 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countn_px(unsigned long n)
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

static int	ft_print_px(unsigned long n, int fd)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		ft_print_px(n / 16, fd);
		ft_print_px(n % 16, fd);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), fd);
		else
			ft_putchar_fd((n - 10 + 'a'), fd);
	}
	len = ft_countn_px(n);
	return (len);
}

int	ft_fprint_p(unsigned long n, int fd)
{
	int	len;

	len = 0;
	write(1, "0x", 2);
	len += ft_print_px(n, fd);
	return (len + 2);
}
