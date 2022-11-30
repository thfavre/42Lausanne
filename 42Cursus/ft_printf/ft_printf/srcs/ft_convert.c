/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:21:04 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/22 14:14:49 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//-----------------------------------------------------------------------------
//function name: ft_itoh
//
//description: convert int value to ascii hex format
//-----------------------------------------------------------------------------

char	ft_itoh(long nbr, int maj)
{
	char	hex[17];
	char	hexm[17];

	ft_strlcpy(hex, "0123456789abcdef", 17);
	ft_strlcpy(hexm, "0123456789ABCDEF", 17);
	if (!maj)
		return (hex[nbr]);
	else
		return (hexm[nbr]);
}

//-----------------------------------------------------------------------------
//function name: ft_ptoa
//
//description: convert pointer value into str
//-----------------------------------------------------------------------------

char	*ft_ptoa(void *pointer)
{
	char			*str;
	unsigned long	pointeradd;
	int				i;

	i = 0;
	pointeradd = (unsigned long)pointer;
	if (!pointeradd)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = '0';
		return (str);
	}
	if (pointeradd == (unsigned long)LONG_MIN)
		return (ft_strdup("8000000000000000"));
	if (pointeradd == ULONG_MAX)
		return (ft_strdup("ffffffffffffffff"));
	str = ft_calloc(pointer_len(pointer) + 1, sizeof(pointer));
	while (pointeradd >= 16)
	{
		str[i++] = ft_itoh(pointeradd % 16, 0);
		pointeradd /= 16;
	}
	if (pointeradd > 0)
		str[i] = ft_itoh(pointeradd, 0);
	return (ft_strrev(str));
}
