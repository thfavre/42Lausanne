/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:22:05 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/12 17:54:05 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	str_size(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		output_char_nb;
	int		i;
	int		j;
	int		kl[2];
	char	*output;

	i = -1;
	output_char_nb = (size - 1) * str_size(sep);
	while (++i < size)
		output_char_nb += str_size(strs[i]);
	output = malloc(sizeof(char) * output_char_nb);
	i = -1;
	kl[0] = 0;
	while (kl[0] < output_char_nb)
	{
		i++;
		j = -1;
		while (i < size && strs[i][++j])
			output[kl[0]++] = strs[i][j];
		kl[1] = -1;
		while (sep[++kl[1]] && kl[0] < output_char_nb)
			output[kl[0]++] = sep[kl[1]];
	}
	return (output);
}
//int main(int A, char **B) { printf("%s", ft_strjoin(A-2, B+2, *(B+1))); }
