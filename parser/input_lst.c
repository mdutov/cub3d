/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:48:12 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 21:25:24 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	lst_free(t_data_input **input_lst)
{
	t_data_input	*begin;
	t_data_input	*next_list;

	begin = *input_lst;
	while (begin)
	{
		next_list = begin->next;
		free(begin->str);
		begin->str = NULL;
		free(begin);
		begin = next_list;
	}
	*input_lst = NULL;
}

int	create_input_lst(char *line, t_data_input **input_lst)
{
	*input_lst = (t_data_input *)malloc(sizeof(t_data_input));
	if (!(*input_lst))
		return (-1);
	(*input_lst)->next = NULL;
	(*input_lst)->str = ft_strdup(line);
	if (!(*input_lst))
	{
		free(input_lst);
		return (-1);
	}
	return (1);
}

int	add_line_in_lst_1(char *line, t_data_input **input_lst,
t_data_input	*new_lst, t_data_input	*tmp)
{
	new_lst = (t_data_input *)malloc(sizeof(t_data_input));
	if (!new_lst)
		return (-1);
	new_lst->next = NULL;
	new_lst->str = ft_strdup(line);
	if (!(new_lst->str))
	{
		free(new_lst);
		return (-1);
	}
	tmp = *input_lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_lst;
	return (1);
}

int	add_line_in_lst(char *line, t_data_input **input_lst)
{
	t_data_input	*new_lst;
	t_data_input	*tmp;
	int				res;

	res = 0;
	new_lst = NULL;
	tmp = NULL;
	if (*input_lst == NULL)
	{
		if (create_input_lst(line, input_lst) == -1)
			return (-1);
	}
	else
		res = add_line_in_lst_1(line, input_lst, new_lst, tmp);
	return (res);
}
