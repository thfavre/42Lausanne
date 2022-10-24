/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:50:31 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/02 00:45:55 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort(int *tab, int size)
{
	int	have_changed;
	int	swap;
	int	i;

	have_changed = 0;
	i = 0;
	while (i < size - 1)
	{
		if (*(tab + i) > *(tab + i + 1))
		{
			swap = *(tab + i + 1);
			*(tab + i + 1) = *(tab + i);
			*(tab + i) = swap;
			have_changed = 1;
			break ;
		}
		i++;
	}
	if (have_changed)
	{
		sort(tab, size);
	}
}	

void	ft_sort_int_tab(int *tab, int size)
{
	sort(tab, size);
}

/*int main()
{
	int tab[] = {3, 2, 1, 4};
	ft_sort_int_tab(tab, 4);
	for (int i=0; i<4; i++) printf(" %d ",tab[i]);
}*/
