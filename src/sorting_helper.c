/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:04:53 by wlin              #+#    #+#             */
/*   Updated: 2017/08/07 14:53:22 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns index of max
int				max_stack(t_stack *s, int size)
{
	int max;
	int ind;

	ind = -1;
	if (size == 0)
		return (0);
	else if (size < 0)
		return (-1);
	max = s->stack[s->top];
	while (--size > -1)
	{
		if (s->stack[size] > max)
		{
			max = s->stack[size];
			ind = size;
		}
	}
	return(ind == -1 ? s->top : ind);
}

//returns index of min
int				min_stack(t_stack *s, int size)
{
	int min;
	int ind;

	ind = -1;
	if (size == 0)
		return (0);
	else if (size < 0)
		return (-1);
	min = s->stack[s->top];
	while (--size > -1)
	{
		if (s->stack[size] < min)
		{
			min = s->stack[size];
			ind = size;
		}
	}
	return(ind == -1 ? s->top : ind);
}

//finds index to insert
int				find_insert(int n, t_stack *s)
{
	int max_loc;

	max_loc = max_stack(s, s->top);
	while (!(n > s->stack[max_loc]))
	{
		if (max_loc == 0)
			max_loc = s->top;
		else
			--max_loc;
	}
	return (max_loc);
}

// find min steps to the next element smaller than pivot
int				find_steps(t_stack *s, int pivot, char c)
{
	int pos;

	if (c == 'T')
	{
		pos = s->top;
		while (pos > -1)
		{
			if (s->stack[pos] < pivot)
				return (s->top - pos + 1);
			pos--;
		}
	}
	if (c == 'B')
	{
		pos = 0;
		while (pos <= s->top)
		{
			if (s->stack[pos] < pivot)
				return (pos - 0 + 2);
			pos++;
		}
	}
	return (-1);
}
