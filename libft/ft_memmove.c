/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:35:39 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:08:09 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*lasts;
	unsigned char	*lastd;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == 0 && s == 0)
		return (NULL);
	if (n != 0)
	{
		if (d < s)
			while (n--)
				*d++ = *s++;
		else
		{
			lasts = s + (n - 1);
			lastd = d + (n - 1);
			while (n--)
				*lastd-- = *lasts--;
		}
	}
	return (dest);
}
