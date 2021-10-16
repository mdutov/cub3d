/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:53:33 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:21:16 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	dgt;

	if (n < 0)
		ft_putchar_fd('-', fd);
	dgt = (unsigned int)ft_nonsign(n);
	if (dgt >= 10)
	{
		ft_putnbr_fd(dgt / 10, fd);
		ft_putnbr_fd(dgt % 10, fd);
	}
	else
		ft_putchar_fd(dgt + '0', fd);
}
