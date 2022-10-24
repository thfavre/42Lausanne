/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:07:08 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/08 22:31:13 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb > 1)
		return (ft_recursive_factorial(nb - 1) * nb);
	else if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	return (nb);
}

//int main() { printf("%i", ft_recursive_factorial(-3));  }
