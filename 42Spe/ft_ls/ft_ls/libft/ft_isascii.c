/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:04:00 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/24 17:28:22 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return ((c <= 127) && (c >= 0));
}

// #include <stdio.h>
// int main(){printf("%d\n", ft_isascii('a'));}