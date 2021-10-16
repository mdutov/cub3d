/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:04:20 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:28:17 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

void	clear_sprite(t_sprite **sprite_start)
{
	t_sprite	*begin;
	t_sprite	*next_list;

	if (!sprite_start || !(*sprite_start))
		return ;
	begin = *sprite_start;
	while (begin)
	{
		next_list = begin->next;
		free(begin);
		begin = next_list;
	}
	*sprite_start = NULL;
}

int	add_sprite2(t_sprite **sprite_start, t_data_sprite *data_sp,
t_sprite *new, t_sprite *iter)
{
	new->length = data_sp->length;
	new->x = data_sp->x;
	new->y = data_sp->y;
	if ((*sprite_start)->length <= data_sp->length)
	{
		new->next = *sprite_start;
		*sprite_start = new;
		return (1);
	}
	else if ((iter)->next == NULL)
		new->next = NULL;
	else if ((iter)->next->length <= data_sp->length)
	{
		if ((iter)->next->x == data_sp->x && (iter)->next->y == data_sp->y)
		{
			free(new);
			return (1);
		}
		new->next = (iter)->next;
	}
	iter->next = new;
	return (1);
}

int	add_sprite1(t_sprite **sprite_start, t_data_sprite *data_sp)
{
	t_sprite	*new;
	t_sprite	*iter;

	iter = *sprite_start;
	if ((iter)->x == data_sp->x && (iter)->y == data_sp->y)
		return (1);
	if ((*sprite_start)->length > data_sp->length)
	{
		while (iter->next != NULL && (iter)->next->length > data_sp->length)
		{
			if ((iter)->x == data_sp->x && (iter)->y == data_sp->y)
				return (1);
			iter = (iter)->next;
		}
	}
	if ((iter)->x == data_sp->x && (iter)->y == data_sp->y)
		return (1);
	new = (t_sprite *)malloc(sizeof(t_sprite));
	if (!(new))
		return (0);
	add_sprite2(sprite_start, data_sp, new, iter);
	return (1);
}

int	add_sprite(t_sprite **sprite_start, double x,
double y, t_player player)
{
	t_data_sprite	data_sp;

	data_sp.length = sqrt((player.x - x) * (player.x - x) + (
				(player.y - y)) * (player.y - y));
	if (data_sp.length > 3000)
		return (1);
	if (*sprite_start == NULL)
	{
		*sprite_start = (t_sprite *)malloc(sizeof(t_sprite));
		if (!(*sprite_start))
			return (0);
		(*sprite_start)->next = NULL;
		(*sprite_start)->length = data_sp.length;
		(*sprite_start)->x = x;
		(*sprite_start)->y = y;
	}
	else
	{
		data_sp.x = x;
		data_sp.y = y;
		if (add_sprite1(sprite_start, &data_sp) == 0)
			return (0);
	}
	return (1);
}

void	receive_sprite_ray(t_player *player, t_data_angle *angle,
t_sprite *sprite, t_data **data_array)
{
	t_sprite_calculation	calc;

	calc.d_phi = angle->d_phi;
	calc.sp_width = 16;
	calc.sp_heigh = 32;
	while (sprite != NULL)
	{
		receive_calc(sprite, &calc, player, data_array);
		draw_sprite(&calc, data_array, angle);
		sprite = sprite->next;
	}
}
