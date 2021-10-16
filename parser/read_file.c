/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:47:47 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/09 18:47:49 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_map_name(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[--i] != 'b')
		return (-19);
	if (s[--i] != 'u')
		return (-19);
	if (s[--i] != 'c')
		return (-19);
	if (s[--i] != '.')
		return (-19);
	return (1);
}

int	read_file1(t_data_input **input_lst,
char *line, int fd)
{
	if (add_line_in_lst(line, input_lst) == -1)
	{
		lst_free(input_lst);
		close(fd);
		return (-4);
	}
	free(line);
	line = NULL;
	return (1);
}

int	read_file(char **argv, t_data_input **input_lst)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-3);
	line = NULL;
	while (get_next_line(fd, &line) == 1)
		if (read_file1(input_lst, line, fd) == -4)
			return (-4);
	free(line);
	close(fd);
	return (1);
}
