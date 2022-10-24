/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_doubl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:11:37 by nrossel           #+#    #+#             */
/*   Updated: 2022/09/11 22:44:45 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_sols_2(int nb);
char	*ft_sols_3(int nb);
char	*ft_sols_4(int nb);

char	*ft_sols_1(int nb)
{
	if (nb == 1)
		return ("1234");
	else if (nb == 2)
		return ("1243");
	else if (nb == 3)
		return ("1324");
	else if (nb == 4)
		return ("1342");
	else if (nb == 5)
		return ("1423");
	else if (nb == 6)
		return ("1432");
	else
		return (ft_sols_2(nb));
}

char	*ft_sols_2(int nb)
{
	if (nb == 7)
		return ("2134");
	else if (nb == 8)
		return ("2143");
	else if (nb == 9)
		return ("2314");
	else if (nb == 10)
		return ("2341");
	else if (nb == 11)
		return ("2413");
	else if (nb == 12)
		return ("2431");
	else
		return (ft_sols_3(nb));
}

char	*ft_sols_3(int nb)
{
	if (nb == 13)
		return ("3124");
	else if (nb == 14)
		return ("3142");
	else if (nb == 15)
		return ("3214");
	else if (nb == 16)
		return ("3241");
	else if (nb == 17)
		return ("3412");
	else if (nb == 18)
		return ("3421");
	else
		return (ft_sols_4(nb));
}

char	*ft_sols_4(int nb)
{
	if (nb == 19)
		return ("4123");
	else if (nb == 20)
		return ("4132");
	else if (nb == 21)
		return ("4213");
	else if (nb == 22)
		return ("4231");
	else if (nb == 23)
		return ("4312");
	else
		return ("4321");
}
