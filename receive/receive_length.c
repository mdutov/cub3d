/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:53:15 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/23 17:13:24 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

static double	receive_distance(t_player player, double x1, double y1,
double phi)
{
	double	distance;

	distance = sqrt((player.x - x1) * (player.x - x1) + (player.y - y1) * (
				(player.y - y1))) * fabs(cos(phi - player.pov * M_PI / 180));
	if (isnan(distance))
		return (INFINITY);
	return (distance);
}

static t_data_draw	receive_distance_original(t_collis collis,
t_player player, double phi)
{
	t_data_draw	data_draw;

	data_draw.length = ft_abs(collis.x - player.x) + (
			ft_abs(collis.y - player.y));
	data_draw.offset = collis.offset;
	if (phi == 0)
		data_draw.side = 'r';
	else if (phi == M_PI / 2)
		data_draw.side = 'u';
	else if (phi == M_PI)
		data_draw.side = 'l';
	else
		data_draw.side = 'd';
	return (data_draw);
}

static t_data_draw	compare_distance(t_collis horisont, t_collis vertical,
t_player player, double phi)
{
	double			distance_h;
	double			distance_v;
	t_data_draw		data_draw;

	distance_h = receive_distance(player, horisont.x, horisont.y, phi);
	distance_v = receive_distance(player, vertical.x, vertical.y, phi);
	if (distance_v > distance_h)
	{
		if (phi < M_PI)
			data_draw.side = 'u';
		else
			data_draw.side = 'd';
		data_draw.length = distance_h;
		data_draw.offset = horisont.offset;
		return (data_draw);
	}
	if (phi < M_PI / 2 || phi > 3 * M_PI / 2)
		data_draw.side = 'r';
	else
		data_draw.side = 'l';
	data_draw.length = distance_v;
	data_draw.offset = vertical.offset;
	return (data_draw);
}

t_data_draw	receive_length(t_vars *vars, t_data_angle *angle,
		t_sprite **sprite)
{
	t_data_draw		data_draw;
	t_collis		collis;
	t_collis		horisont;
	t_collis		vertical;
	double			phi;

	phi = angle->new_phi;
	if (phi == 0 || phi == M_PI / 2 || phi == M_PI || phi == 3 * M_PI / 2)
	{
		collis = find_block_unique(phi, vars, sprite);
		data_draw = receive_distance_original(collis, vars->player, phi);
	}
	else
	{
		horisont = find_block_horisontal(vars, phi, sprite);
		vertical = find_block_vertical(vars, phi, sprite);
		data_draw = compare_distance(horisont, vertical, vars->player, phi);
	}
	angle->arr_length[angle->count] = data_draw.length;
	return (data_draw);
}
