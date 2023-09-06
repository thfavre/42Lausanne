/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:50:13 by thomas            #+#    #+#             */
/*   Updated: 2023/04/27 15:45:01 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 1;
	while (i < ac)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)toupper(av[i][j]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
