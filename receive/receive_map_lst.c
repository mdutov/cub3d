/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_map_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:53:35 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 16:53:36 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive.h"

void	pars_map_lst_1(t_my_map	*new, char *line, t_my_map	*tmp)
{
	new->next = NULL;
	new->length = ft_strlen(line);
	new->line = ft_strdup(line);
	tmp->next = new;
}

int	pars_map_lst(char *line, t_vars *vars)
{
	t_my_map	*new;
	t_my_map	*tmp;

	if (vars->map_lst == NULL)
	{
		vars->map_lst = (t_my_map *)malloc(sizeof(t_my_map));
		if (!(vars->map_lst))
			return (-1);
		vars->map_lst->next = NULL;
		vars->map_lst->line = ft_strdup(line);
		vars->map_lst->length = ft_strlen(line);
		return (1);
	}
	else
	{
		tmp = vars->map_lst;
		while (tmp->next)
			tmp = tmp->next;
	}
	new = (t_my_map *)malloc(sizeof(t_my_map));
	if (!(new))
		return (-1);
	pars_map_lst_1(new, line, tmp);
	return (1);
}

int	receive_map_lst(char *line, t_vars *vars)
{
	if (vars->flags.map_end == 1)
		return (-16);
	vars->flags.map_start = 1;
	if (pars_map_lst(line, vars) != 1)
	{
		free_map_lst(vars);
		return (-16);
	}
	return (1);
}
