/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:35:38 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:41:40 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	size_t	i;

	rtn = NULL;
	rtn = ft_newstr(ft_strlen(s));
	if (s && f && rtn)
	{
		i = 0;
		while (s[i])
		{
			rtn[i] = f(i, s[i]);
			i++;
		}
		rtn[i] = '\0';
	}
	return (rtn);
}
