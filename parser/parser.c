/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:47:35 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/24 18:39:12 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parser1(t_vars *vars, t_data_input **input_lst)
{
	int		res;

	res = malloc_vars(vars);
	if (res != 1)
	{
		lst_free(input_lst);
		return (res);
	}
	res = receive_param(vars, *input_lst);
	if (res != 1)
	{
		lst_free(input_lst);
		free_map_vars(vars);
		return (res);
	}
	lst_free(input_lst);
	return (1);
}

int	parser_2(char **argv, t_vars *vars, int res, t_data_input	*input_lst)
{
	res = check_map_name(argv[1]);
	if (res != 1)
		return (res);
	res = read_file(argv, &input_lst);
	if (res != 1)
		return (res);
	res = parser1(vars, &input_lst);
	if (res != 1)
		return (res);
	res = receive_img(vars);
	if (res != 1)
		return (res);
	return (res);
}

int	parser(int argc, char **argv, t_vars *vars)
{
	int				res;
	t_data_input	*input_lst;

	res = 0;
	input_lst = NULL;
	if (argc != 2 && argc != 3)
		return (-2);
	res = parser_2(argv, vars, res, input_lst);
	if (argc == 3 && res == 1)
	{
		res = screenshot(vars, argv);
		if (res != 1)
			return (res);
		free_map_vars(vars);
		exit(0);
	}
	return (res);
}
