/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:53:25 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:38:01 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

int	receive_length_x(t_my_map *map_lst)
{
	int		number;

	number = 0;
	while (map_lst)
	{
		map_lst = map_lst->next;
		number++;
	}
	return (number);
}

static int	make_malloc_map(t_vars *vars)
{
	int			i;
	t_my_map	*lst;

	vars->map = (char **)malloc(sizeof(char *) * (
				(vars->length_map_y + 1)));
	if (!(vars->map))
		return (-1);
	vars->map[vars->length_map_y] = NULL;
	i = 0;
	lst = vars->map_lst;
	while (i < vars->length_map_y)
	{
		vars->map[i] = lst->line;
		lst = lst->next;
		i++;
	}
	return (1);
}

int	receive_map(t_vars *vars)
{
	vars->length_map_y = receive_length_x(vars->map_lst);
	if (make_malloc_map(vars) == -1)
		return (-1);
	return (1);
}
