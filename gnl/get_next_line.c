/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:04:39 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:02:26 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	next_str_to_buf(char **line, char *buf)
{
	int				len;
	char			*del_ln;

	del_ln = *line;
	*line = ft_strjoin(*line, buf);
	ft_memdel((void **)&del_ln);
	len = BUFFER_SIZE - ft_strlen(buf);
	ft_memmove(buf, buf + ft_strlen(buf) + 1, len);
	ft_memset((void *)(buf + len), 0, BUFFER_SIZE - len);
}

int	get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*ptr;
	int				rd;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (read(fd, buf, 0)) < 0)
		return (-1);
	*line = ft_strjoin("", "");
	rd = 1;
	while (rd && rd != -1)
	{
		ptr = ft_strchr(buf, '\n');
		if (ptr)
			*ptr = '\0';
		next_str_to_buf(line, buf);
		if (ptr)
			return (1);
		rd = read(fd, buf, BUFFER_SIZE);
	}
	return (rd);
}
