/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:00:51 by mchepil           #+#    #+#             */
/*   Updated: 2017/12/20 16:43:30 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int		word;
	int		i;

	if (!s)
		return (0);
	i = 1;
	word = 0;
	while (s[i])
	{
		if (i == 1 && s[0] != c)
			word++;
		if (s[i] != c && s[i - 1] == c && s[i])
			word++;
		i++;
	}
	return (word);
}

char			**ft_strsplit(char *s, char c)
{
	int		i;
	int		w;
	int		start;
	char	**str;

	if (!s)
		return (0);
	i = 0;
	w = 0;
	if (!(str = (char**)malloc(sizeof(char*) * ft_count_word(s, c) + 1)))
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		str[w] = ft_strsub(s, start, (i - start));
		if (w < ft_count_word(s, c))
			w++;
		i++;
	}
	str[w] = 0;
	return (str);
}
