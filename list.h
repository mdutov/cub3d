/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:39:42 by maxim             #+#    #+#             */
/*   Updated: 2021/05/10 22:42:09 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct				s_data
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	int						width;
	int						height;
	double					d;

}							t_data;

typedef struct				s_coord
{
	int						wall_horis_x;
	int						wall_horis_y;
	int						wall_vertical_x;
	int						wall_vertical_y;
	int						collis_x;
	int						collis_y;

}							t_coord;

typedef struct				s_player
{
	int						x;
	int						y;
	int						check;
	double					pov;

}							t_player;

typedef struct				s_sprite
{
	double					x;
	double					y;
	double					length;
	double					h;
	struct s_sprite			*next;
	struct s_sprite			*prev;

}							t_sprite;

typedef struct				s_sprite_data
{
	double					length;
	int						x;
	int						y;

}							t_sprite_data;

typedef struct				s_sprite_calculation
{
	double					dx;
	double					dy;
	double					distance;
	double					theta;
	double					gamma;
	double					x0_sprite;
	double					y0_sprite;
	double					length;
	double					d_phi;
	double					wall_length;
	int						sp_width;
	int						sp_heigh;
	int						h;
	int						real_h;
	double					step_y;
	double					step_x;
	int						middle_sprite;
	int						ray_pov;
	int						ray_center;
	int						delta_rays;

}							t_sprite_calculation;

typedef struct				s_collis
{
	double					x;
	double					y;
	double					offset;
	int						err;
	t_sprite				*sprite;

}							t_collis;

typedef struct				s_coord_uniq
{
	int						ax;
	int						ay;
	int						dx;
	int						dy;

}							t_coord_uniq;

typedef struct				s_coord_horis
{
	double					ax;
	double					ay;
	double					dx;
	double					dy;

}							t_coord_horis;

typedef struct				s_coord_vertic
{
	double					bx;
	double					by;
	double					dx;
	double					dy;

}							t_coord_vertic;

typedef struct				s_data_map
{
	int						map_len_x;
	int						map_len_y;
	int						size_cub;
	char					(*map)[10];

}							t_data_map;

typedef struct				s_data_draw
{
	char					side;
	double					length;
	double					offset;
	int						h;
	int						color;
	int						x_count;

}							t_data_draw;

typedef struct				s_data_angle
{
	double					phi;
	double					new_phi;
	double					d_phi;
	int						count;
	int						*arr_length;

}							t_data_angle;

typedef struct				s_keyboard
{
	int						a;
	int						d;
	int						w;
	int						s;
	int						left;
	int						right;

}							t_keyboard;

typedef struct				s_draw_sprite
{
	int						x;
	int						y;
	unsigned int			color;
	double					y_xmp;
	double					x_xmp;

}							t_draw_sprite;

typedef struct				s_flags
{
	int						no;
	int						so;
	int						we;
	int						ea;
	int						s;
	int						f;
	int						c;
	int						r;
	int						summ;
	int						map_start;
	int						map_end;

}							t_flags;

typedef struct				s_my_map
{
	char					*line;
	int						length;
	struct s_my_map			*next;

}							t_my_map;

typedef struct				s_draw_line
{
	int						delta_x;
	int						delta_y;
	int						er;
	int						er2;
	int						dy;
	int						dx;

}							t_draw_line;

typedef struct				s_coord_line
{
	int						y1;
	int						x1;
	int						y0;
	int						x0;

}							t_coord_line;

typedef struct				s_data_sprite
{
	double					length;
	double					x;
	double					y;

}							t_data_sprite;

typedef struct				s_xy_data
{
	int						x;
	int						y;

}							t_xy_data;

typedef struct				s_vars
{
	void					*mlx;
	void					*win;
	t_player				player;
	t_data_map				data_map;
	t_keyboard				keyboard;
	t_data					**data_array;
	t_flags					flags;
	t_my_map				*map_lst;
	char					*dir_wall_left;
	char					*dir_wall_right;
	char					*dir_wall_up;
	char					*dir_wall_down;
	char					*dir_sprite;
	char					**map;
	int						length_map_y;
	int						color_floor;
	int						color_ceilling;
	int						max_width;
	int						max_height;

}							t_vars;

typedef struct				s_data_input
{
	char					*str;
	struct s_data_input		*next;

}							t_data_input;

#endif
