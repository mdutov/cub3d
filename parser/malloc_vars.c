/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:47:21 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/20 22:50:27 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	null_vars_file(t_vars *vars)
{
	vars->dir_sprite = NULL;
	vars->dir_wall_left = NULL;
	vars->dir_wall_up = NULL;
	vars->dir_wall_right = NULL;
	vars->dir_wall_down = NULL;
	vars->map = NULL;
	vars->map_lst = NULL;
}

void	null_flags(t_vars *vars)
{
	vars->player.check = 0;
	vars->keyboard.left = 0;
	vars->keyboard.right = 0;
	vars->keyboard.a = 0;
	vars->keyboard.w = 0;
	vars->keyboard.d = 0;
	vars->keyboard.s = 0;
	vars->flags.we = 0;
	vars->flags.no = 0;
	vars->flags.ea = 0;
	vars->flags.so = 0;
	vars->flags.c = 0;
	vars->flags.f = 0;
	vars->flags.s = 0;
	vars->flags.r = 0;
	vars->flags.map_start = 0;
	vars->flags.map_end = 0;
	vars->flags.summ = 0;
}

int	malloc_vars(t_vars *vars)
{
	int	i;

	i = 0;
	vars->data_array = (t_data **)malloc(6 * sizeof(t_data *));
	if (!(vars->data_array))
		return (-5);
	while (i < 6)
	{
		vars->data_array[i++] = (t_data *)malloc(sizeof(t_data));
		if (!(vars->data_array[i - 1]))
		{
			while (--i >= 0)
				free(vars->data_array[i]);
			free(vars->data_array);
			return (-5);
		}
	}
	null_vars_file(vars);
	null_flags(vars);
	receive_width_height(vars);
	return (1);
}
