/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:10:56 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/23 16:51:23 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	function_1(char	*bgn, char	*dest, char const *s1, char const *s2)
{
	if (dest)
	{
		if (s1)
			while (*s1)
				*bgn++ = *s1++;
		if (s2)
			while (*s2)
				*bgn++ = *s2++;
		*bgn = '\0';
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*bgn;
	char	*dest;
	size_t	n1;
	size_t	n2;

	n1 = 0;
	n2 = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		n1 = ft_strlen(s1);
	if (s2)
		n2 = ft_strlen(s2);
	dest = ft_newstr(n1 + n2);
	bgn = dest;
	function_1(bgn, dest, s1, s2);
	return (dest);
}
