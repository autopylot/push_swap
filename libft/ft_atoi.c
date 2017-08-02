/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:38:42 by wlin              #+#    #+#             */
/*   Updated: 2017/07/15 11:22:58 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (!*s || !s)
		return (0);
	while (WS(*s))
		++s;
	if (*s == '-' || *s == '+')
		sign = (*s++ == '+' ? 1 : -1);
	while (ft_isdigit(*s))
		num = num * 10 + (*s++ - '0');
	return ((int)num * sign);
}