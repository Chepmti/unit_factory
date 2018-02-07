/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:40:13 by mchepil           #+#    #+#             */
/*   Updated: 2017/11/14 14:12:22 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define TABS(a) a == ' ' || (a >= 9 && a <= 13)

int				ft_atoi(const char *str)
{
	long			res;
	long			sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (TABS(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res > 99999999999 && sign == 1)
			return (-1);
		else if (res < -99999999999 && sign == -1)
			return (0);
		i++;
	}
	return ((int)res * (int)sign);
}
