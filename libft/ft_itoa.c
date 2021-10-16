/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 02:32:39 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:16:14 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n, int minus)
{
	int	nlen;
	int	r;

	nlen = 1;
	r = (n /= 10);
	while (r)
		nlen++;
	return (nlen + minus);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		nlen;
	int		minus;
	int		nbr;

	if (n < 0)
		minus = 1;
	else
		minus = 0;
	nlen = ft_nlen(n, minus);
	dest = ft_newstr(nlen);
	if (dest)
	{
		dest[nlen--] = '\0';
		while (nlen >= minus)
		{
			nbr = n % 10;
			dest[nlen--] = '0' + ft_nonsign(nbr);
			n /= 10;
		}
		if (minus)
			dest[0] = '-';
	}
	return (dest);
}
