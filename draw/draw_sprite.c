/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:02:53 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:41:27 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	receive_dr_sp(t_draw_sprite *dr_sp, t_data **data_array,
t_sprite_calculation *calc)
{
	dr_sp->y_xmp = 0;
	dr_sp->y = (data_array[0]->height - calc->real_h) / 2
		+ calc->real_h - calc->h;
	if (dr_sp->y < 0)
		dr_sp->y = 0;
}

void	put_pixel_sprite(t_data **data_array, t_draw_sprite *dr_sp)
{
	if (dr_sp->x_xmp < data_array[5]->width)
	{
		dr_sp->color = receive_color_sprite(*data_array[5],
				(int)floor(dr_sp->y_xmp), (int)floor(dr_sp->x_xmp));
		if (dr_sp->color != 0xff000000)
			my_mlx_pixel_put(data_array[0], dr_sp->x, dr_sp->y, dr_sp->color);
	}
}

void	draw_left_part(t_data **data_array, t_sprite_calculation *calc,
t_data_angle *angle)
{
	t_draw_sprite	dr_sp;

	dr_sp.x = calc->middle_sprite;
	dr_sp.x_xmp = data_array[5]->width / 2;
	while (dr_sp.x >= 0 && dr_sp.x_xmp >= 0)
	{
		receive_dr_sp(&dr_sp, data_array, calc);
		while (dr_sp.y < data_array[0]->height && dr_sp.y < (
				(calc->real_h + data_array[0]->height)) / 2)
		{
			if (dr_sp.x >= data_array[0]->width)
				break ;
			if (angle->arr_length[dr_sp.x] < calc->length)
				break ;
			put_pixel_sprite(data_array, &dr_sp);
			dr_sp.y_xmp += calc->step_y;
			dr_sp.y++;
		}
		dr_sp.x_xmp -= calc->step_x;
		dr_sp.x--;
	}
}

void	draw_right_part(t_data **data_array,
t_sprite_calculation *calc, t_data_angle *angle)
{
	t_draw_sprite	dr_sp;

	dr_sp.x = calc->middle_sprite;
	dr_sp.x_xmp = data_array[5]->width / 2;
	while (dr_sp.x < data_array[0]->width && dr_sp.x_xmp < data_array[5]->width)
	{
		receive_dr_sp(&dr_sp, data_array, calc);
		while (dr_sp.y < data_array[0]->height && dr_sp.y < (
				(calc->real_h + data_array[0]->height)) / 2)
		{
			if (dr_sp.x <= 0)
				break ;
			if (angle->arr_length[dr_sp.x] < calc->length)
				break ;
			put_pixel_sprite(data_array, &dr_sp);
			dr_sp.y_xmp += calc->step_y;
			dr_sp.y++;
		}
		dr_sp.x_xmp += calc->step_x;
		dr_sp.x++;
	}
}

void	draw_sprite(t_sprite_calculation *calc,
t_data **data_array, t_data_angle *angle)
{
	draw_left_part(data_array, calc, angle);
	draw_right_part(data_array, calc, angle);
}
