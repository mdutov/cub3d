/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:47:05 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/20 22:46:59 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

void	free_map_vars(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(vars->data_array[i]);
		vars->data_array[i] = NULL;
		i++;
	}
	free(vars->data_array);
	free(vars->dir_wall_left);
	free(vars->dir_wall_up);
	free(vars->dir_wall_right);
	free(vars->dir_wall_down);
	free(vars->dir_sprite);
	free(vars->map);
	free_map_lst(vars);
}

void	free_map_lst(t_vars *vars)
{
	t_my_map	*next;

	while (vars->map_lst)
	{
		next = vars->map_lst->next;
		free(vars->map_lst->line);
		vars->map_lst->line = NULL;
		free(vars->map_lst);
		vars->map_lst = next;
	}
}

void	free_screen(char **screen)
{
	int	i;

	i = 0;
	while (screen[i])
	{
		free(screen[i]);
		screen[i] = NULL;
		i++;
	}
	free(screen);
}
