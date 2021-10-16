/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:37:50 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 18:32:42 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

void	switch_w(t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	delta_x = (int)nearbyint(cos(vars->player.pov * M_PI / 180) * 5);
	delta_y = -(int)nearbyint(sin(vars->player.pov * M_PI / 180) * 5);
	if (vars->map[(vars->player.y + delta_y) / 64]
		[(vars->player.x + delta_x) / 64] != '1')
	{
		vars->player.x += delta_x;
		vars->player.y += delta_y;
		return ;
	}
}

void	switch_d(t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	delta_x = (int)nearbyint(cos((vars->player.pov - 90) * M_PI / 180) * 5);
	delta_y = -(int)nearbyint(sin((vars->player.pov - 90) * M_PI / 180) * 5);
	if (vars->map[(vars->player.y + delta_y) / 64]
		[(vars->player.x + delta_x) / 64] != '1')
	{
		vars->player.x += delta_x;
		vars->player.y += delta_y;
		return ;
	}
}

void	switch_s(t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	delta_x = -(int)nearbyint(cos(vars->player.pov * M_PI / 180) * 5);
	delta_y = (int)nearbyint(sin(vars->player.pov * M_PI / 180) * 5);
	if (vars->map[(vars->player.y + delta_y) / 64]
		[(vars->player.x + delta_x) / 64] != '1')
	{
		vars->player.x += delta_x;
		vars->player.y += delta_y;
		return ;
	}
}

void	switch_a(t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	delta_x = -(int)nearbyint(cos((vars->player.pov - 90) * M_PI / 180) * 5);
	delta_y = (int)nearbyint(sin((vars->player.pov - 90) * M_PI / 180) * 5);
	if (vars->map[(vars->player.y + delta_y) / 64]
		[(vars->player.x + delta_x) / 64] != '1')
	{
		vars->player.x += delta_x;
		vars->player.y += delta_y;
		return ;
	}
}

int	switch_coord(t_vars *vars)
{
	if (vars->keyboard.w)
		switch_w(vars);
	if (vars->keyboard.d)
		switch_d(vars);
	if (vars->keyboard.s)
		switch_s(vars);
	if (vars->keyboard.a)
		switch_a(vars);
	if (vars->player.pov < 0)
		vars->player.pov += 360;
	if (vars->player.pov >= 360)
		vars->player.pov -= 360;
	if (vars->keyboard.right)
		vars->player.pov -= 4;
	if (vars->keyboard.left)
		vars->player.pov += 4;
	return (0);
}
