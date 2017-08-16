/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:04:53 by wlin              #+#    #+#             */
/*   Updated: 2017/08/16 13:07:26 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				find_max(t_stack *s, int len, char c)
{
	int max;
	int ind;

	ind = -1;
	if (len == 0)
		return (0);
	else if (len == -1)
		return (-1);
	max = s->stack[len];
	while (--len > -1)
	{
		if (s->stack[len] > max)
		{
			max = s->stack[len];
			ind = len;
		}
	}
	if (c == 'I')
		return ((ind == -1) ? s->top : ind);
	return (max);
}

int				find_min(t_stack *s, int len, char c)
{
	int min;
	int ind;

	ind = -1;
	if (len == 0)
		return (0);
	else if (len == -1)
		return (-1);
	min = s->stack[len];
	while (--len > -1)
	{
		if (s->stack[len] < min)
		{
			min = s->stack[len];
			ind = len;
		}
	}
	if (c == 'I')
		return ((ind == -1) ? s->top : ind);
	return (min);
}

int				find_insert(int n, t_stack *s)
{
	int ins_loc;

	ins_loc = find_min(s, s->top, 'I');
	if (n > find_max(s, s->top, 'V'))
		return (ins_loc);
	while (!(n < s->stack[ins_loc]))
	{
		if (ins_loc == 0)
			ins_loc = s->top;
		else
			--ins_loc;
	}
	return (ins_loc);
}

int				find_next(t_stack *s, int pivot, char c)
{
	int top;
	int bot;

	top = s->top;
	bot = 0;
	while (top > bot)
	{
		if (s->stack[top] < pivot)
			return (c == 'I' ? top : s->stack[top]);
		else if (s->stack[bot] < pivot)
			return (c == 'I' ? bot : s->stack[bot]);
		--top;
		++bot;
	}
	if (c == 'I')
		return (-1);
	return (pivot);
}

int			find_ind(t_stack *s, int nbr)
{
	int ind;

	ind = s->top;
	while (ind > -1)
	{
		if (s->stack[ind] == nbr)
			return (ind);
		--ind;
	}
	return (-1);
}
