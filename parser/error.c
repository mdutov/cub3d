/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:47:14 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/10 22:26:52 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	error_1(int code_error)
{
	if (code_error == -9)
		write(2, "Invalid north texture\n", 22);
	else if (code_error == -10)
		write(2, "Invalid west texture\n", 21);
	else if (code_error == -11)
		write(2, "Invalid south texture\n", 22);
	else if (code_error == -12)
		write(2, "Multiple identical parameters\n", 30);
	else if (code_error == -13)
		write(2, "Invalid color of floor\n", 23);
	else if (code_error == -14)
		write(2, "Invalid color of ceilling\n", 26);
	else if (code_error == -15)
		write(2, "Invalid sprite texture\n", 23);
	else if (code_error == -16)
		write(2, "Invalid map\n", 12);
	else if (code_error == -17)
		write(2, "Player doesn't exist\n", 21);
	else if (code_error == -18)
		write(2, "Мore than one player\n", 21);
	else if (code_error == -19)
		write(2, "Invalid name of map config\n", 27);
	else
		return ;
}

void	error(int code_error)
{
	write(2, "Error! --> ", 11);
	if (code_error == -2)
		write(2, "Wrong number of parameters\n", 27);
	else if (code_error == -3)
		write(2, "Error opening map config (*.cub)\n", 33);
	else if (code_error == -4)
		write(2, "GNL couldn't add new line\n", 26);
	else if (code_error == -5)
		write(2, "Malloc didn't do his job\n", 25);
	else if (code_error == -6)
		write(2, "Error opening xpm\n", 18);
	else if (code_error == -7)
		write(2, "Invalid map\n", 12);
	else if (code_error == -8)
		write(2, "Invalid screen resolution\n", 26);
	else if (code_error == -20)
		write(2, "Invalid east texture\n", 21);
	else
		error_1(code_error);
}
