/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:46:24 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 20:23:38 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_player(t_vars *vars, char direction, int x, int y)
{
	if (vars->player.check == 1)
		return (-18);
	vars->player.check = 1;
	vars->player.x = x * 64 + 32;
	vars->player.y = y * 64 + 32;
	if (direction == 'N')
	{
		vars->player.pov = 90.0;
	}
	else if (direction == 'W')
	{
		vars->player.pov = 180.0;
	}
	else if (direction == 'S')
		vars->player.pov = 270.0;
	else
		vars->player.pov = 0.0;
	return (1);
}

int	check_valid(t_vars *vars, int x, int y)
{
	if (check_up(vars->map, x, y) == -1 || (
			check_bottom(vars->map, x, y, vars->length_map_y)) == -1 || (
			check_left(vars->map, x, y)) == -1 || (
			check_right(vars->map, x, y)) == -1)
		return (-7);
	return (1);
}

int	valid_and_player(t_vars *vars, char c, int y, int x)
{
	int	res;

	res = check_valid(vars, x, y);
	if (res != 1)
		return (res);
	res = check_player(vars, c, x, y);
	if (res != 1)
		return (res);
	return (1);
}

static int	check_line(t_vars *vars, char *line, int y)
{
	int		x;
	int		res;

	x = -1;
	res = 1;
	while (line[++x])
	{
		if (line[x] == '1' || line[x] == ' ' || line[x] == '\0')
			continue ;
		else if (line[x] == '2' || line[x] == '0')
			res = check_valid(vars, x, y);
		else if (line[x] == 'N' || line[x] == 'W' || (
				line[x]) == 'S' || line[x] == 'E')
			res = valid_and_player(vars, line[x], y, x);
		else
			return (-16);
		if (res != 1)
			return (res);
	}
	return (res);
}

int	check_map(t_vars *vars)
{
	int		y;
	int		res;

	y = 0;
	if (vars->flags.summ != 8)
		return (-2);
	while (vars->map[y])
	{
		res = check_line(vars, vars->map[y], y);
		if (res != 1)
			return (res);
		y++;
	}
	if (vars->player.check != 1)
		return (-17);
	return (1);
}
