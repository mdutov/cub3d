/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:53:50 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 16:53:51 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

int	check_letter(char *line, t_vars *vars)
{
	if (*line == '1' && vars->flags.map_end == 1)
		return (-7);
	if (*line == 'R')
		return (receive_screen_param(line, vars));
	else if (*line == 'N')
		return (receive_north_texture(line, vars));
	else if (*line == 'W')
		return (receive_west_texture(line, vars));
	else if (*line == 'E')
		return (receive_east_texture(line, vars));
	else if (*line == 'F')
		return (receive_floor_color(line, vars));
	else if (*line == 'C')
		return (receive_ceilling_color(line, vars));
	else if (*line == 'S')
		return (receive_s(line, vars));
	else
		return (-2);
}

int	check_line(char *line, t_vars *vars)
{
	int	res;
	int	i;

	i = 0;
	if (*line == '1' || *line == ' ')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			vars->flags.map_start = 1;
			res = receive_map_lst(line, vars);
			return (res);
		}
	}
	while (*line == ' ' || *line == '\t' || *line == '\f'
		|| *line == '\v' || *line == '\r')
		line++;
	if (*line == '\0')
	{
		if (vars->flags.map_start == 1)
			vars->flags.map_end = 1;
		return (1);
	}
	return (check_letter(line, vars));
}

int	receive_param(t_vars *vars, t_data_input *input_lst)
{
	int				res;

	while (input_lst)
	{
		res = check_line(input_lst->str, vars);
		if (res != 1)
		{
			return (res);
		}
		input_lst = input_lst->next;
	}
	receive_map(vars);
	res = check_map(vars);
	if (res != 1)
		return (res);
	return (1);
}
