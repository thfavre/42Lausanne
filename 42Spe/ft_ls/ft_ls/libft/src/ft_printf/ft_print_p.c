/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:45:45 by berard            #+#    #+#             */
/*   Updated: 2022/11/14 15:08:40 by berard           ###   ########.fr       */
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

static int	ft_print_px(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		ft_print_px(n / 16);
		ft_print_px(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
	len = ft_countn_px(n);
	return (len);
}

int	ft_print_p(unsigned long n)
{
	int	len;

	len = 0;
	write(1, "0x", 2);
	len += ft_print_px(n);
	return (len + 2);
}
