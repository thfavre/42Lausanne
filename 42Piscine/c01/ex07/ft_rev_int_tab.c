/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:14:56 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/01 23:49:54 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	swap;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		swap = *(tab + i);
		*(tab + i) = *(tab + size - i - 1);
		*(tab + size - i - 1) = swap;
		i++;
	}
}
/*int	main() 
{
	int tab[] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(tab, 5);
	for (int i=0; i<5; i++) printf(" %d ",tab[i]);
}*/
