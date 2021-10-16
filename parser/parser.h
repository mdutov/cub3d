/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:26:42 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 21:03:26 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../headers.h"

int							read_file(char **argv,
								t_data_input **input_lst);
int							add_line_in_lst(char *line,
								t_data_input **input_lst);
void						lst_free(t_data_input **input_lst);
void						error(int error_code);
void						free_map_vars(t_vars *vars);
int							check_up(char **map, int x, int y);
int							check_bottom(char **map, int x, int y,
								int length_map_y);
int							check_left(char **map, int x, int y);
int							check_right(char **map, int x, int y);
int							parser(int argc, char **argv, t_vars *vars);
int							malloc_vars(t_vars *vars);
int							num_screen_param(char **screen);
void						free_map_lst(t_vars *vars);
int							check_map(t_vars *vars);
int							check_map_name(char *s);

#endif