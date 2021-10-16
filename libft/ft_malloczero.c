/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloczero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:13:20 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:18:40 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloczero(size_t size)
{
	void	*dest;

	dest = malloc(size);
	if (dest)
		ft_bzero(dest, size);
	return (dest);
}
