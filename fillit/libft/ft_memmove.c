/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:39:33 by mchepil           #+#    #+#             */
/*   Updated: 2017/11/13 16:49:09 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	s1 = (char *)dst;
	s2 = (const char *)src;
	i = 0;
	if (s1 < s2)
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
		{
			s1[len] = s2[len];
		}
	}
	return (dst);
}
