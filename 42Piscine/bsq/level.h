/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:07:08 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/21 22:07:13 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

typedef struct s_data
{
	int		size;
	char	empty;
	char	obstacle;
	char	square;
}	t_data;

typedef struct s_level
{
	int		is_correct;
	t_data	data;
	char	**map;
}	t_level;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_square_data
{
	int		size;
	t_point	pos;
}	t_square_data;

#endif
