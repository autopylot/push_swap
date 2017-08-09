/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:04:53 by wlin              #+#    #+#             */
/*   Updated: 2017/08/09 14:44:07 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns max value or index
int				find_max(t_stack s, int len, char c)
{
	int max;
	int ind;

	ind = -1;
	if (len == 0)
		return (0);
	else if (len < 0)
		return (-1);
	max = s.stack[s.top];
	while (--len > -1)
	{
		if (s.stack[size] > max)
		{
			max = s->stack[size];
			ind = size;
		}
	}
	if (c == 'I')
		return ((ind == -1) ? s->top : ind);
	return (max);
}

//returns min value or index
int				find_min(t_stack *s, int len, char c)
{
	int min;
	int ind;

	ind = -1;
	// if (size == 0)
	// 	return (0);
	// else if (size < 0)
	// 	return (-1);
	min = s->stack[len];
	while (--len > -1)
	{
		if (s->stack[len] < min)
		{
			min = s->stack[len];
			ind = len;
			// printf("min val: %d\n", s->stack[len]);
			// printf("index of min: %d\n", len);
		}
	}
	//printf("%d\n", ind);
	if (c == 'I')
	{
		//puts("exiting here");
		return ((ind == -1) ? s->top : ind);
	}
	return (min);
}

//finds index to insert
int				find_insert(int n, t_stack *s)
{
	int ins_loc;

	ins_loc = find_max(s, s->top, 'I');
	if (n < find_min(s, s->top, 'V'))
		return (ins_loc);
	while (!(n > s->stack[ins_loc]))
	{
		if (ins_loc == 0)
			ins_loc = s->top;
		else
			--ins_loc;
	}
	return (ins_loc);
}

// find next element smaller than pivot with least steps
int				next_sort(t_stack *s, int pivot, char c)
{
	int top;
	int bot;

	top = s->top;
	bot = 0;
	while (top > bot)
	{
		if (s->stack[top] <= pivot)
			return (c == 'I' ? top : s->stack[top]);
		else if (s->stack[bot] <= pivot)
			return (c == 'I' ? bot : s->stack[bot]);
		--top;
		++bot;
	}
	if (c == 'I')
		return (-1);
	return (pivot);
}
