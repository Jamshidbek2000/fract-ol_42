/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:19:35 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 18:50:04 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

void	free_instances(t_instances *instances)
{
	free(instances->point);
	free(instances->axe);
	free(instances->mouse);
	free(instances);
	instances = NULL;
}

void	terminate(t_instances *instances)
{
	if (instances == NULL)
		return ;
	mlx_terminate(instances->mlx);
	free_instances(instances);
}

void	leak_check(void)
{
	system("leaks fractol");
}
