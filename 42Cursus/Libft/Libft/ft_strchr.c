/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:23:38 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/24 17:35:48 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strrchr(const char *s, int c)
{
    unsigned int    i;

    i = 0;
    while (s[i] != '\0' && s[i++] != c)
        s++;
    if (s[i] != c)
        return (NULL);
    return (s + i);
}

#include <stdio.h>

int main()
{printf("%s\n", ft_strrchr("aBcdef", 'c'));}