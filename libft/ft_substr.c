/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:23:35 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:43:49 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*ptr;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len <= start)
		len = 0;
	if (str_len > len)
		str_len = len;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memcpy(ptr, s + start, str_len + 1);
	ptr[len] = '\0';
	return (ptr);
}
