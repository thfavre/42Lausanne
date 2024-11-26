/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:08:52 by berard            #+#    #+#             */
/*   Updated: 2024/11/26 18:35:41 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprint_di(int n, int fd)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	len = ft_strlen(str);
	free (str);
	return (len);
}
