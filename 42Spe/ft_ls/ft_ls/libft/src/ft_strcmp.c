/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 00:06:59 by thfavre           #+#    #+#             */
/*   Updated: 2024/09/30 18:26:44 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2) {
		if (*s1 == '\0') {
			return 0;
		}
		s1++;
		s2++;
	}
	// if (*(unsigned char *)s1 < *(unsigned char *)s2)
	// 	return (-1);
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
