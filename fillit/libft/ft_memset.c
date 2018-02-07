/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:46:41 by mchepil           #+#    #+#             */
/*   Updated: 2017/11/13 16:51:18 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	if (n)
	{
		d = dst;
		while (i < n)
		{
			d[i] = c;
			i++;
		}
	}
	return (dst);
}