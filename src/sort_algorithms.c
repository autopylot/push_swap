/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:02:40 by wlin              #+#    #+#             */
/*   Updated: 2017/08/16 12:54:59 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubblesort(t_stack *s, char c)
{
	if (is_ordered(s))
	{
		roto_next(s, find_min(s, s->top, 'I'), c);
		return ;
	}
	swap(s, c);
	if (is_ordered(s))
		roto_next(s, find_min(s, s->top, 'I'), c);
}

void	insort(t_stack *s1, t_stack *s2, char c)
{
	int ins_pos;
	int	ins_num;

	if (s2->top < 1)
		move(s1, s2, c);
	else
	{

		ins_num = find_optimal(s1, s2);
		//printf("Optimal ind to ins from stack1: %d\n", ins_num);
		ins_pos = find_insert(s1->stack[ins_num], s2);
		int s1top = s1->stack[ins_num];
		int s2top = s2->stack[ins_pos];
		roto_both(s1, ins_num, s2, ins_pos);
		if (s1->stack[s1->top] != s1top)
			roto_next(s1, find_ind(s1, s1top), 'b');
		if (s2->stack[s2->top] != s2top)
			roto_next(s2, find_ind(s2, s2top), 'a');
		// print_stack(s2, 'a');
		//roto_next(s2, ins_pos, c);
		// print_stack(s2, 'a');
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
	while ((pos = find_next(s1, pivot, 'I')) > -1)
	{
		atop = s1->stack[pos];
		roto_both(s1, pos, s2, find_insert(s1->stack[pos], s2));
		if (s1->stack[s1->top] != atop)
			roto_next(s1, find_ind(s1, atop), 'b');
		insort(s1, s2, 'b');
	}
	//swap_top(a, 'a');
	if (!is_ordered(s1) && s1->top > 2)
	{
		// roto_both(a, pos, b, find_insert(pivot, b));
		// if (a->stack[a->top] != pivot)
		roto_next(s1, find_ind(s1, pivot), 'a');
		insort(s1, s2, 'a');
	}
	free(copy);
}
