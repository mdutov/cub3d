/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_param_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:07:24 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 16:45:25 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

void	receive_width_height(t_vars *vars)
{
	mlx_get_screen_size(&(vars->max_width), &(vars->max_height));
}

int	receive_height_1(char *str, t_vars *vars)
{
	while (*str == '0')
		str++;
	if (*str == '\0')
	{
		vars->data_array[0]->height = vars->max_height;
		return (1);
	}
	else
		return (-1);
}

int	receive_width_1(char *str, t_vars *vars)
{
	while (*str == '0')
		str++;
	if (*str == '\0')
	{
		vars->data_array[0]->width = MIN_WIDTH;
		return (1);
	}
	else
		return (-1);
}
