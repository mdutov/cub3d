/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:03:50 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 16:45:25 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

int	receive_s(char *line, t_vars *vars)
{
	int	out;

	line++;
	if (*line == 'O')
		out = receive_south_texture(line, vars);
	else if (*line == ' ' || *line == '\t' || *line == '\f'
		|| *line == '\v' || *line == '\r')
		out = receive_sprite_texture(line, vars);
	else
		return (-2);
	return (out);
}
