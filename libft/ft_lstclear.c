/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:22:07 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:17:20 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*begin;
	t_list	*next_list;

	if (!lst || !del)
		return ;
	begin = *lst;
	while (begin)
	{
		next_list = begin->next;
		del(begin->content);
		free(begin);
		begin = next_list;
	}
	*lst = NULL;
}
