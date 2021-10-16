/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 01:38:05 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:11:25 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rtn;

	rtn = NULL;
	while (*s)
	{
		if (*s == c)
			rtn = (char *)s;
		s++;
	}
	if (*s == c && c == '\0')
		return ((char *)s);
	return (rtn);
}
