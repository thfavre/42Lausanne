/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:39:53 by thfavre           #+#    #+#             */
/*   Updated: 2023/01/17 21:39:54 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

// ---------- Vector 2 ---------- //
//	int
typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

// ---------- Vector 3 ---------- //
// int
typedef struct s_vector3
{
	int	x;
	int	y;
	int	z;
}	t_vector3;

typedef struct s_dvector3
{
	double	x;
	double	y;
	double	z;
}	t_dvector3;

#endif
