/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:54:30 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/30 16:28:51 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

void	move_real(t_instances *instances, double move_by)
{
	t_axe	*axe;

	axe = instances->axe;
	axe->x_offset += move_by;
}

void	move_imaginary(t_instances *instances, double move_by)
{
	t_axe	*axe;

	axe = instances->axe;
	axe->y_offset += move_by;
}
