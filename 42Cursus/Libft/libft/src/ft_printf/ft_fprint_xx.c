/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:31:05 by berard            #+#    #+#             */
/*   Updated: 2024/11/26 18:36:30 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countn_xx(unsigned int n)
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

int	ft_fprint_xx(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		ft_fprint_xx(n / 16, fd);
		ft_fprint_xx(n % 16, fd);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), fd);
		else
			ft_putchar_fd((n - 10 + 'A'), fd);
	}
	len = ft_countn_xx(n);
	return (len);
}
