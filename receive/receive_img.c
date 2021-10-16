/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:53:05 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:15:52 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

int	receive_img_3(t_vars *vars)
{
	vars->data_array[4]->addr = mlx_get_data_addr(vars->data_array[4]->img,
			&(vars->data_array[4]->bits_per_pixel),
			&(vars->data_array[4]->line_length),
			&(vars->data_array[4]->endian));
	vars->data_array[5]->img = mlx_xpm_file_to_image(vars->mlx,
			vars->dir_sprite, &vars->data_array[5]->width,
			&vars->data_array[5]->height);
	if (!(vars->data_array[5]->img))
		return (-6);
	vars->data_array[5]->addr = mlx_get_data_addr(vars->data_array[5]->img,
			&(vars->data_array[5]->bits_per_pixel),
			&(vars->data_array[5]->line_length),
			&(vars->data_array[5]->endian));
	return (1);
}

int	receive_img_2(t_vars *vars)
{
	int	img_width;
	int	img_heigh;
	int	res;

	vars->data_array[3]->img = mlx_xpm_file_to_image(vars->mlx,
			vars->dir_wall_down, &img_width, &img_heigh);
	if (!(vars->data_array[3]->img))
		return (-6);
	vars->data_array[3]->addr = mlx_get_data_addr(vars->data_array[3]->img,
			&(vars->data_array[3]->bits_per_pixel),
			&(vars->data_array[3]->line_length),
			&(vars->data_array[3]->endian));
	vars->data_array[4]->img = mlx_xpm_file_to_image(vars->mlx,
			vars->dir_wall_right, &img_width, &img_heigh);
	if (!(vars->data_array[4]->img))
		return (-6);
	res = receive_img_3(vars);
	return (res);
}

int	receive_img_1(t_vars *vars)
{
	int		img_width;
	int		img_heigh;

	vars->data_array[1]->img = mlx_xpm_file_to_image(vars->mlx,
			vars->dir_wall_left, &img_width, &img_heigh);
	if (!(vars->data_array[1]->img))
		return (-6);
	vars->data_array[1]->addr = mlx_get_data_addr(vars->data_array[1]->img,
			&(vars->data_array[1]->bits_per_pixel),
			&(vars->data_array[1]->line_length),
			&(vars->data_array[1]->endian));
	vars->data_array[2]->img = mlx_xpm_file_to_image(vars->mlx,
			vars->dir_wall_up, &img_width, &img_heigh);
	if (!(vars->data_array[2]->img))
		return (-6);
	vars->data_array[2]->addr = mlx_get_data_addr(vars->data_array[2]->img,
			&(vars->data_array[2]->bits_per_pixel),
			&(vars->data_array[2]->line_length),
			&(vars->data_array[2]->endian));
	return (1);
}

int	receive_img(t_vars *vars)
{
	int		res;

	vars->mlx = mlx_init();
	vars->data_array[0]->img = mlx_new_image(vars->mlx,
			vars->data_array[0]->width, vars->data_array[0]->height);
	vars->data_array[0]->addr = mlx_get_data_addr(vars->data_array[0]->img,
			&(vars->data_array[0]->bits_per_pixel),
			&(vars->data_array[0]->line_length),
			&(vars->data_array[0]->endian));
	vars->win = mlx_new_window(vars->mlx, vars->data_array[0]->width,
			vars->data_array[0]->height, "cub3D");
	vars->data_array[0]->d = vars->data_array[0]->width / (
			(2 * tan(33 * M_PI / 180)));
	res = receive_img_1(vars);
	if (res != 1)
		return (res);
	res = receive_img_2(vars);
	if (res != 1)
		return (res);
	return (1);
}
