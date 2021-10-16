/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_floor_and_celling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:03:21 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:14:39 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

static int	check_digit(char *param)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (param == NULL)
		return (-1);
	if (*param == '\0')
		return (-1);
	while (param[i] == ' ' || param[i] == '\t' || param[i] == '\f'
		|| param[i] == '\v' || param[i] == '\r')
		i++;
	while (ft_isdigit(param[i++]) != 0)
		n++;
	while (param[i] == ' ' || param[i] == '\t'
		|| param[i] == '\f' || param[i] == '\v' || param[i] == '\r')
		i++;
	if (param[i] != '\0')
		return (-1);
	if (n > 3)
		return (-1);
	return (1);
}

int	color_parser(char **param)
{
	int	color;
	int	r;
	int	g;
	int	b;

	if (check_digit(param[0]) == -1 || check_digit(param[1]) == -1 || (
			check_digit(param[2])) == -1)
		return (-1);
	r = ft_atoi(param[0]);
	if (r > 255)
		return (-1);
	g = ft_atoi(param[1]);
	if (g > 255)
		return (-1);
	b = ft_atoi(param[2]);
	if (b > 255)
		return (-1);
	color = 256 * 256 * r + 256 * g + b;
	return (color);
}

int	check_comma(char *str)
{
	int		n;

	n = 0;
	while (*str)
	{
		if (*str == ',')
			n++;
		if (n > 2)
			return (-1);
		str++;
	}
	return (1);
}

int	receive_floor_color(char *line, t_vars *vars)
{
	char	**param;

	if (vars->flags.f == 1)
		return (-12);
	line++;
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
			|| *line == '\v' || *line == '\r'))
		return (-13);
	while (*line == ' ' || *line == '\t' || *line == '\f'
		|| *line == '\v' || *line == '\r')
		line++;
	param = ft_split(line, ',');
	vars->color_floor = color_parser(param);
	if (check_comma(line) == -1 || num_screen_param(param) != 3
		|| vars->color_floor == -1)
	{
		free_screen(param);
		return (-13);
	}
	vars->flags.f = 1;
	vars->flags.summ += 1;
	free_screen(param);
	return (1);
}

int	receive_ceilling_color(char *line, t_vars *vars)
{
	char	**param;

	if (vars->flags.c == 1)
		return (-12);
	line++;
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
			|| *line == '\v' || *line == '\r'))
		return (-14);
	while (*line == ' ' || *line == '\t' || *line == '\f'
		|| *line == '\v' || *line == '\r')
		line++;
	param = ft_split(line, ',');
	vars->color_ceilling = color_parser(param);
	if (check_comma(line) == -1 || num_screen_param(param) != 3
		|| vars->color_ceilling == -1)
	{
		free_screen(param);
		return (-14);
	}
	vars->flags.c = 1;
	vars->flags.summ += 1;
	free_screen(param);
	return (1);
}
