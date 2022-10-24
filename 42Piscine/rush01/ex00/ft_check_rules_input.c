/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rules_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:06:09 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/11 23:16:01 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_rules_input(char **input, int nb_prmt)
{
	int	i;

	if (nb_prmt != 2)
		return (0);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0 && !(input[1][i] >= '1' && input[1][i] <= '4'))
			return (0);
		else if (i % 2 == 1 && input[1][i] != ' ')
			return (0);
		i++;
	}
	if (input[1][i] == '\0')
		return (1);
	return (0);
}
