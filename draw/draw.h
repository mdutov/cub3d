/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:26:42 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/21 22:58:35 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../headers.h"

void	print_line(t_coord_line coord, t_data *img);
void	draw_ray(double pov, t_player player, char (*map)[10], t_data *img);
int		draw_3d(t_vars *vars);
void	draw_sprite(t_sprite_calculation *calc,
			t_data **data_array, t_data_angle *angle);
void	draw_vertical_line(t_data_draw data_draw, t_vars *vars);
void	draw_ground(int *y, t_data_draw data_draw, t_vars *vars);
void	draw_wall(int *y, t_data_draw data_draw, t_data **data_array);
void	draw_sky(int *y, t_data_draw data_draw, t_vars *vars);
int		add_sprite(t_sprite **sprite_start,
			double x, double y, t_player player);
void	clear_sprite(t_sprite **sprite_start);
void	draw_sprite(t_sprite_calculation *calc,
			t_data **data_array, t_data_angle *angle);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif