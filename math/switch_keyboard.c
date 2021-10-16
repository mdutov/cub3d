/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:37:59 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 18:34:22 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	switch_on_keyboard(int keycode, t_vars *vars)
{
	if (keycode == 0)
		vars->keyboard.a = 1;
	if (keycode == 13)
		vars->keyboard.w = 1;
	if (keycode == 2)
		vars->keyboard.d = 1;
	if (keycode == 1)
		vars->keyboard.s = 1;
	if (keycode == 123)
		vars->keyboard.left = 1;
	if (keycode == 124)
		vars->keyboard.right = 1;
	return (0);
}

int	switch_off_keyboard(int keycode, t_vars *vars)
{
	if (keycode == 0)
		vars->keyboard.a = 0;
	if (keycode == 13)
		vars->keyboard.w = 0;
	if (keycode == 2)
		vars->keyboard.d = 0;
	if (keycode == 1)
		vars->keyboard.s = 0;
	if (keycode == 123)
		vars->keyboard.left = 0;
	if (keycode == 124)
		vars->keyboard.right = 0;
	if (keycode == 53)
	{
		free_map_vars(vars);
		exit(0);
	}
	return (0);
}
