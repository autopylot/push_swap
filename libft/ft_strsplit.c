/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:50:32 by wlin              #+#    #+#             */
/*   Updated: 2017/07/15 19:26:46 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_length(char const *s, char c, unsigned int i)
{
	unsigned int len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		++len;
		++i;
	}
	return (len);
}

static int	ft_array_length(char const *s, char c)
{
	unsigned int len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			++s;
		else
		{
			++len;
			while (*s && *s != c)
				++s;
		}
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**ar;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(ar = (char **)malloc(sizeof(char *) * (ft_array_length(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(ar[j++] = ft_strsub(s, i, ft_word_length(s, c, i))))
				return (NULL);
			i += ft_word_length(s, c, i);
		}
		else
			i++;
	}
	ar[j] = NULL;
	return (ar);
}
