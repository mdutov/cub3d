/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:26:42 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:41:28 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include "../headers.h"

t_collis					find_collision(double phi, t_vars *vars);
t_collis					find_block_unique(double phi, t_vars *vars,
								t_sprite **sprite);
t_collis					find_block_horisontal(t_vars *vars, double phi,
								t_sprite **sprite);
t_collis					find_block_vertical(t_vars *vars, double phi,
								t_sprite **sprite);
int							switch_on_keyboard(int keycode, t_vars *vars);
int							switch_off_keyboard(int keycode, t_vars *vars);
unsigned int				receive_color(t_data data, int y,
								double offset, int h);
unsigned int				receive_color_sprite(t_data data, int y, int x);
void						free_screen(char **screen);
void						free_map_vars(t_vars *vars);
int							switch_coord(t_vars *vars);
int							screenshot(t_vars *vars, char **argv);

#endif