/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:52:51 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:13:10 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

void	receive_calc_3(t_sprite_calculation *calc, t_data **data_array)
{
	calc->delta_rays = (int)(calc->gamma / calc->d_phi);
	calc->ray_pov = data_array[0]->width / 2;
	calc->middle_sprite = calc->ray_pov + calc->delta_rays;
}

void	receive_calc_2(t_sprite_calculation *calc,
t_player *player, t_data **data_array)
{
	double	d_gamma;

	d_gamma = acos((calc->distance - calc->sp_width * cos((90 - calc->gamma) * (
						M_PI) / 180)) / sqrt(calc->sp_width * calc->sp_width + (
					calc->distance) * calc->distance - 2 * calc->sp_width * (
					calc->distance) * cos((90 - calc->gamma) * M_PI / 180))) * (
			180) / M_PI;
	calc->step_x = data_array[5]->width / 2 / (d_gamma / calc->d_phi);
	if (player->pov >= 0 && player->pov < 33)
	{
		if (calc->theta >= 327)
			calc->gamma = player->pov + (360 - calc->theta);
		else
			calc->gamma = player->pov - calc->theta;
	}
	else if (player->pov >= 327 && player->pov < 360)
	{
		if (calc->theta <= 33)
			calc->gamma = -(360 - player->pov + calc->theta);
		else
			calc->gamma = player->pov - calc->theta;
	}
	else
		calc->gamma = player->pov - calc->theta;
	receive_calc_3(calc, data_array);
}

void	receive_calc_1(t_sprite *sprite, t_sprite_calculation *calc,
t_player *player, t_data **data_array)
{
	calc->dx = sprite->x - player->x;
	calc->dy = player->y - sprite->y;
	calc->distance = sprite->length;
	calc->theta = atan2(calc->dy, calc->dx);
	if (calc->theta < 0)
		calc->theta += 2 * M_PI;
	calc->theta = calc->theta * 180 / M_PI;
	calc->length = calc->distance * (
			fabs(cos((player->pov - calc->theta) * M_PI / 180)));
	calc->real_h = (int)floor(data_array[0]->d * 64.0 / calc->length);
	calc->h = (int)floor(data_array[0]->d * calc->sp_heigh / calc->length);
	calc->step_y = (double)data_array[5]->height / (double)calc->h;
	calc->gamma = player->pov - calc->theta;
}

void	receive_calc(t_sprite *sprite, t_sprite_calculation *calc,
t_player *player, t_data **data_array)
{
	receive_calc_1(sprite, calc, player, data_array);
	receive_calc_2(calc, player, data_array);
}
