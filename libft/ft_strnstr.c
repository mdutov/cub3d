/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:10:45 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:42:53 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[t] != '\0' && t != len)
	{
		if (haystack[t] == needle[0])
		{
			i = 0;
			while (haystack[t + i] == needle[i] && needle[i] && t + i < len)
				i++;
			if (needle[i] == '\0')
				return ((char *)(haystack + t));
		}
		t++;
	}
	return (NULL);
}
