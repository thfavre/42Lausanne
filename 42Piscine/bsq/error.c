/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:28:28 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/21 23:08:11 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"
#include <unistd.h>
#include <stdlib.h>

int	print_error(int n)
{
	if (n == 1)
		write(1, "map error\n", 10);
	return (0);
}

int	print_errors(int n, char *frees)
{
	if (n == 1)
		write(1, "map error\n", 10);
	free(frees);
	return (0);
}
