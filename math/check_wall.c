/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:38:05 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:47:24 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	check_up(char **map, int x, int y)
{
	if (y == 0)
		return (-1);
	while (y >= 0)
	{
		if (x > (int)ft_strlen(map[y]) - 1)
			return (-1);
		if (map[y][x] == ' ')
			return (-1);
		if (map[y][x] == '1')
			return (1);
		y--;
	}
	return (-1);
}

int	check_bottom(char **map, int x, int y, int length_map_y)
{
	if (y == length_map_y - 1)
		return (-1);
	while (y <= length_map_y - 1)
	{
		if (x > (int)ft_strlen(map[y]) - 1)
			return (-1);
		if (map[y][x] == ' ')
			return (-1);
		if (map[y][x] == '1')
			return (1);
		y++;
	}
	return (-1);
}

int	check_left(char **map, int x, int y)
{
	if (x == 0)
		return (-1);
	while (x >= 0)
	{
		if (map[y][x] == ' ')
			return (-1);
		if (map[y][x] == '1')
			return (1);
		x--;
	}
	return (-1);
}

int	check_right(char **map, int x, int y)
{
	int		len_map_y;

	len_map_y = (int)ft_strlen(map[y]) - 1;
	if (x == len_map_y)
		return (-1);
	while (x <= len_map_y)
	{
		if (map[y][x] == ' ')
			return (-1);
		if (map[y][x] == '1')
			return (1);
		x++;
	}
	return (-1);
}
