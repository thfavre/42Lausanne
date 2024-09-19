/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:26:23 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/10 14:19:50 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		str = ft_itoa(n);
		if (str != NULL)
		{
			ft_putstr_fd(str, fd);
			free(str);
		}
	}
}
