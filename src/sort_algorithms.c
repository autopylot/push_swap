/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:02:40 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 12:46:51 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(t_stack *s, char c)
{
	if (!is_ordered(s))
		swap(s, c);
	roto_next(s, find_min(s, s->top, 'I'), c);
}

void	insort(t_stack *s1, t_stack *s2, char c)
{
	int ins_next;
	int ins_pos;
	int s1top;
	int s2top;

	if (s2->top < 1)
		move(s1, s2, c);
	else
	{

		ins_next = find_optimal(s1, s2);
		ins_pos = find_insert(s1->stack[ins_next], s2);
		s1top = s1->stack[ins_next];
		s2top = s2->stack[ins_pos];
		roto_both(s1, ins_next, s2, ins_pos);
		if (s1->stack[s1->top] != s1top)
			roto_next(s1, find_ind(s1, s1top), 'b');
		if (s2->stack[s2->top] != s2top)
			roto_next(s2, find_ind(s2, s2top), 'a');
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

	copy = (int*)malloc(sizeof(int) * (s1->top + 1));
	ft_memcpy(copy, s1->stack, sizeof(int) * (s1->top + 1));
	pivot = find_median(copy, s1->top + 1);
	swap_top(s1, 'a');
	while ((pos = find_next(s1, pivot, 'I')) > -1)
	{
		//atop = s1->stack[pos];
		roto_next(s1, pos, 'a');
		// roto_both(s1, pos, s2, find_insert(s1->stack[pos], s2));
		// if (s1->stack[s1->top] != atop)
		// 	roto_next(s1, find_ind(s1, atop), 'b');
		// insort(s1, s2, 'b');
		move(s1, s2, 'b');
	}
	bubblesort(s1, 'a');
	while (!is_empty(s2))
		insort(s2, s1, 'a');
	roto_next(s1, find_min(s1, s1->top, 'I'), 'a');
	// if (!is_ordered(s1) && s1->top > 2)
	// {
	// 	// roto_both(a, pos, b, find_insert(pivot, b));
	// 	// if (a->stack[a->top] != pivot)
	// 	roto_next(s1, find_ind(s1, pivot), 'a');
	// 	insort(s1, s2, 'a');
	// }
	free(copy);
}
