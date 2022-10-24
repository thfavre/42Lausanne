/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:08:13 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/11 22:46:22 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_rules_input(char **input, int nb_prmt);
int	bruteforce(char *rules);

int	main(int argc, char **argv)
{
	if (!ft_check_rules_input(argv, argc))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (bruteforce(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
}
