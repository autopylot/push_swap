/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:53:48 by wlin              #+#    #+#             */
/*   Updated: 2017/08/10 15:10:14 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check a top and swap if top < top -1
void	check_top(t_stack *s, char c)
{
	if (s->top > 0)
	{
		if (s->top - 1 == find_min(s, s->top, 'I'))
		{
			swap(s, c);
		}
	}
}

//check if stack is ordered and just needed to be rotated
int is_ordered(t_stack *s)
{
	int min_loc;
	int i;

	i = s->top;
	min_loc = find_min(s, s->top, 'V');
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

int is_sorted(t_stack *s)
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

//rotates next num to be sorted to the top with least moves
void	roto_next(t_stack *s, int pos, char c)
{
	int next;

	next = s->stack[pos];
	if (pos >= (s->top / 2))
	{
		while (s->stack[s->top] != next)
			rotate(s, c);
	}
	else
		while (s->stack[s->top] != next)
			rev_rotate(s, c);
}


// rotate both stack if they can move in same directions
// must be able to read in from a single string
