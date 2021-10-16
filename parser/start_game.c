/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:47:55 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 21:33:14 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	do_exit(t_vars *vars)
{
	free_map_vars(vars);
	exit(0);
	return (0);
}

int	start_draw(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (draw_3d(vars) == -1)
	{
		free_map_vars(vars);
		exit(0);
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->data_array[0]->img, 0, 0);
	switch_coord(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	int			res;

	res = parser(argc, argv, &vars);
	if (res != 1)
	{
		error(res);
		exit(0);
	}
	mlx_loop_hook(vars.mlx, &start_draw, &vars);
	mlx_hook(vars.win, 2, 0, &switch_on_keyboard, &vars);
	mlx_hook(vars.win, 3, 0, &switch_off_keyboard, &vars);
	mlx_hook(vars.win, 17, 0, &do_exit, &vars);
	mlx_do_sync(vars.mlx);
	mlx_loop(vars.mlx);
	return (0);
}
