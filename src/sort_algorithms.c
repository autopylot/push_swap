/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:02:40 by wlin              #+#    #+#             */
/*   Updated: 2017/08/14 15:00:50 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubblesort(t_stack *a)
{
	if (is_ordered(a))
	{
		roto_next(a, find_min(a, a->top, 'I'), 'a');
		return ;
	}
	swap(a, 'a');
	if (is_ordered(a))
		roto_next(a, find_min(a, a->top, 'I'), 'a');
}

void	insort(t_stack *s1, t_stack *s2, char c)
{
	int ins_pos;
	int	ins_num;

	if (s2->top < 1)
		move(s1, s2, c);
	else
	{
		ins_pos = find_insert(s1->stack[s1->top], s2);
		roto_next(s2, ins_pos, c);
		move(s1, s2, c);
	}
}

void	quicksort(t_stack *s1, t_stack *s2)
{
	int pos;
	int next;
	int atop;
	int pivot;
	int *copy;

	copy = (int*)malloc(sizeof(int) * (a->top + 1));
	ft_memcpy(copy, a->stack, sizeof(int) * (a->top + 1));
	pivot = find_median(copy, a->top + 1);
	while ((pos = find_next(a, pivot, 'I')) > -1)
	{
		atop = a->stack[pos];
		roto_both(a, pos, b, find_insert(a->stack[pos], b));
		if (a->stack[a->top] != atop)
			roto_next(a, find_ind(a, atop), 'b');
		insort(a, b, 'b');
	}
	//swap_top(a, 'a');
	if (!is_ordered(a) && a->top > 2)
	{
		// roto_both(a, pos, b, find_insert(pivot, b));
		// if (a->stack[a->top] != pivot)
		roto_next(a, find_ind(a, pivot), 'a');
		insort(a, b, 'a');
	}
	free(copy);
}
