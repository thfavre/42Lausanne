/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:46:19 by berard            #+#    #+#             */
/*   Updated: 2024/11/26 19:12:43 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(int fd, const char *input, ...)
{
	va_list	args;
	int		len;

	va_start(args, input);
	len = ft_vfprintf(fd, input, args);
	va_end(args);
	return (len);
}
