/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:02:40 by wlin              #+#    #+#             */
/*   Updated: 2017/08/07 15:09:49 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(t_stack *s)
{
	int ind;

	while (!is_ordered(s))
	{
		if (s->stack[s->top - 1] < s->stack[s->top])
			swap(s);
		else
			rotate(s);
		print_stack(s, 'a');
	}
	puts("sorted");
	int mind = min_stack(s, s->top);
	int minval = s->stack[mind];
	while (s->stack[s->top] != minval)
		rotate(s);
	//while (++ind <= )
}

void	insort(t_stack *a, t_stack *b)
{
	int insert;
	int	ins_top;

	if (b->top < 1)
		move(a, b);
	insert = find_insert(a->stack[a->top], b);
	ins_top = b->stack[insert];
	if (insert >= (b->top / 2))
	{
		while (b->stack[b->top] != ins_top)
			rotate(b);
		move(a, b);
	}
	else
		while (b->stack[b->top] != ins_top)
			rev_rotate(b);
		move(a, b);
}

void	quicksort(t_stack *a, t_stack *b)
{
	int pivot;
	int top_step;
	int bot_step;

	pivot = a->stack[a->top / 2];
	while (min_stack(a, a->top) < pivot)
	{
		top_step = find_steps(a, pivot, 'T');
		bot_step = find_steps(a, pivot, 'B');
		while (top_step != -1 && bot_step != -1)
		{
			if (top_step <= bot_step)
				roto_top(a, top_step, 'T');
			else
				roto_top(a, bot_step, 'B');
			insort(a, b);
		}
	}
	move(a, b);
}
