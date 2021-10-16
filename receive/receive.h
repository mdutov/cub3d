/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:42:08 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 22:28:17 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECEIVE_H
# define RECEIVE_H

# include "../headers.h"

t_data_draw					receive_length(t_vars *vars, t_data_angle *angle,
								t_sprite **sprite);
void						receive_sprite_ray(t_player *player,
								t_data_angle *angle, t_sprite *sprite,
								t_data **data_array);
void						receive_calc(t_sprite *sprite,
								t_sprite_calculation *calc, t_player *player,
								t_data **data_array);
int							receive_param(t_vars *vars,
								t_data_input *input_lst);
int							receive_screen_param(char *line, t_vars *vars);
int							receive_north_texture(char *line, t_vars *vars);
int							receive_south_texture(char *line, t_vars *vars);
int							receive_west_texture(char *line, t_vars *vars);
int							receive_east_texture(char *line, t_vars *vars);
int							receive_sprite_texture(char *line, t_vars *vars);
int							receive_s(char *line, t_vars *vars);
int							receive_floor_color(char *line, t_vars *vars);
int							receive_ceilling_color(char *line, t_vars *vars);
int							receive_map_lst(char *line, t_vars *vars);
int							receive_img(t_vars *vars);
int							receive_dx(double phi);
int							receive_dy(double phi);
int							receive_ax(t_player player, double phi);
int							receive_ay(t_player player, double phi);
void						receive_width_height(t_vars *vars);
int							receive_map(t_vars *vars);
int							receive_width_1(char *str, t_vars *vars);
int							receive_height_1(char *str, t_vars *vars);

#endif