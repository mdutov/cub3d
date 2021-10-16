/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:03:59 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:38:40 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

int	receive_north_texture(char *line, t_vars *vars)
{
	line++;
	if (*(line++) != 'O')
		return (-1);
	if (vars->flags.no == 1)
		return (-12);
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
			|| *line == '\v' || *line == '\r'))
		return (-9);
	while (*line == ' ' || *line == '\t' || *line == '\f'
		|| *line == '\v' || *line == '\r')
		line++;
	vars->dir_wall_up = ft_strdup(line);
	if (!(vars->dir_wall_up))
		return (-9);
	vars->flags.no = 1;
	vars->flags.summ += 1;
	return (1);
}

int	receive_south_texture(char *line, t_vars *vars)
{
	if (vars->flags.so == 1)
		return (-12);
	line++;
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
			|| *line == '\v' || *line == '\r'))
		return (-11);
	while (*line == ' ' || *line == '\t' || *line == '\f'
		|| *line == '\v' || *line == '\r')
		line++;
	vars->dir_wall_down = ft_strdup(line);
	if (!(vars->dir_wall_down))
		return (-11);
	vars->flags.so = 1;
	vars->flags.summ += 1;
	return (1);
}

int	receive_west_texture(char *line, t_vars *vars)
{
	line++;
	if (*(line++) != 'E')
		return (-1);
	if (vars->flags.we == 1)
		return (-12);
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
			|| *line == '\v' || *line == '\r'))
		return (-10);
	while (*line == ' ' || *line == '\t' || *line == '\f'
		|| *line == '\v' || *line == '\r')
		line++;
	vars->dir_wall_left = ft_strdup(line);
	if (!(vars->dir_wall_left))
		return (-10);
	vars->flags.we = 1;
	vars->flags.summ += 1;
	return (1);
}

int	receive_east_texture(char *line, t_vars *vars)
{
	line++;
	if (*(line++) != 'A')
		return (-1);
	if (vars->flags.ea == 1)
		return (-12);
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
			|| *line == '\v' || *line == '\r'))
		return (-1);
	while (*line == ' ' || *line == '\t' || *line == '\f'
		|| *line == '\v' || *line == '\r')
		line++;
	vars->dir_wall_right = ft_strdup(line);
	if (!(vars->dir_wall_right))
		return (-1);
	vars->flags.ea = 1;
	vars->flags.summ += 1;
	return (1);
}

int	receive_sprite_texture(char *line, t_vars *vars)
{
	if (vars->flags.s == 1)
		return (-12);
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
			|| *line == '\v' || *line == '\r'))
		return (-15);
	while (*line == ' ' || *line == '\t' || *line == '\f'
		|| *line == '\v' || *line == '\r')
		line++;
	vars->dir_sprite = ft_strdup(line);
	if (!(vars->dir_sprite))
		return (-15);
	vars->flags.s = 1;
	vars->flags.summ += 1;
	return (1);
}
