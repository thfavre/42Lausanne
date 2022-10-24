/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:21:37 by jchapell          #+#    #+#             */
/*   Updated: 2022/09/21 22:58:15 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

int	check_rules(char *parsed)
{
	int	i;

	i = 0;
	if (ft_strlen(parsed) < 6)
		return (1);
	while (parsed[i] != '\n')
		i++;
	if (parsed[i - 1] == parsed[i - 2] || parsed[i - 1] == parsed[i - 3]
		|| parsed[i - 2] == parsed[i - 3])
		return (1);
	if (!(ft_ischarprintable(parsed[i - 1]))
		|| !(ft_ischarprintable(parsed[i - 2]))
		|| !(ft_ischarprintable(parsed[i - 3])))
		return (1);
	return (i);
}

int	check_map(int i, int width, char *parsed, t_data data)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while (parsed[++i])
	{
		if (parsed[i] != data.obstacle && parsed[i] != data.empty
			&& parsed[i] != '\n')
			return (0);
		if (parsed[i] == '\n')
		{
			if (width == -1)
				width = x;
			else if (x != width)
				return (0);
			x = 0;
			j++;
		}
		else
			x++;
	}
	return (j);
}

int	parse_validity(char *parsed, t_data data)
{
	int	i;
	int	j;
	int	width;

	i = check_rules(parsed);
	if (i == 1)
		return (0);
	j = -1;
	while (++j < i - 3)
		if (parsed[j] < '0' || parsed[j] > '9')
			return (0);
	j = 0;
	width = -1;
	j = check_map(i, width, parsed, data);
	if (j == 0)
		return (0);
	if (j != data.size)
		return (0);
	return (1);
}
