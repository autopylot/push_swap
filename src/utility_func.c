/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:50:30 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 12:05:17 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ordered(t_stack *s)
{
	int min_loc;
	int i;

	i = s->top;
	min_loc = find_min(s, s->top, 'I');
	while (i-- > 0)
	{
		if (min_loc == 0)
		{
			if (s->stack[min_loc] < s->stack[s->top])
				min_loc = s->top;
			else
				return (0);
		}
		else
		{
			if (s->stack[min_loc] < s->stack[min_loc - 1])
				--min_loc;
			else
				return (0);
		}
	}
	return (1);
}

int		is_sorted(t_stack *s)
{
	int i;

	i = s->top;
	if (s->top == 0)
		return (1);
	while (i > 0)
	{
		if (!(s->stack[i] < s->stack[i - 1]))
			return (0);
		--i;
	}
	return (1);
}

void	print_stack(t_stack *s, char c)
{
	int i;

	i = s->top;
	while (i > -1)
	{
		printf("[%d] %d\n", i, s->stack[i]);
		if (i == 0)
			printf("[Stack %c]\n", c);
		--i;
	}
}

int		ft_error(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	return (0);
}
