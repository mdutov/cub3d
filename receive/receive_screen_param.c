/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_screen_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:54:03 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:38:26 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

int	num_screen_param(char **screen)
{
	int	len;

	len = 0;
	while (*screen)
	{
		len++;
		screen++;
	}
	return (len);
}

int	check_digit(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*(str++)) == 0)
			return (0);
	}
	return (1);
}

int	receive_width(char *str, t_vars *vars)
{
	int	width;
	int	res;

	width = 0;
	res = receive_width_1(str, vars);
	if (check_digit(str))
	{
		if (ft_strlen(str) > 5)
			vars->data_array[0]->width = vars->max_width;
		else
			width = ft_atoi(str);
		if (width >= vars->max_width)
			vars->data_array[0]->width = vars->max_width;
		else if (width <= MIN_WIDTH)
			vars->data_array[0]->width = MIN_WIDTH;
		else
			vars->data_array[0]->width = width;
		res = 1;
	}
	else
		res = -1;
	return (res);
}

int	receive_height(char *str, t_vars *vars)
{
	int	height;
	int	res;

	height = 0;
	res = receive_height_1(str, vars);
	if (check_digit(str))
	{
		if (ft_strlen(str) > 5)
			vars->data_array[0]->height = vars->max_height;
		else
			height = ft_atoi(str);
		if (height >= vars->max_height)
			vars->data_array[0]->height = vars->max_height;
		else if (height <= MIN_HEIGHT)
			vars->data_array[0]->height = MIN_HEIGHT;
		else
			vars->data_array[0]->height = height;
		res = 1;
	}
	else
		res = -1;
	return (res);
}

int	receive_screen_param(char *line, t_vars *vars)
{
	char	**screen;

	screen = ft_split(line, ' ');
	if (num_screen_param(screen) != 3)
	{
		free_screen(screen);
		return (-8);
	}
	if ((receive_width(screen[1], vars)) == -1)
	{
		free_screen(screen);
		return (-8);
	}
	if (receive_height(screen[2], vars) == -1)
	{
		free_screen(screen);
		return (-8);
	}
	free_screen(screen);
	vars->flags.summ += 1;
	return (1);
}
