/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:02:40 by wlin              #+#    #+#             */
/*   Updated: 2017/08/11 17:15:46 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insort(t_stack *a, t_stack *b)
{
	int ins_pos;
	int	ins_num;

	if (b->top < 1)
		move(a, b, 'b');
	else
	{
		ins_pos = find_insert(a->stack[a->top], b);
		roto_next(b, ins_pos, 'b');
		move(a, b, 'b');
	}
}

void	quicksort(t_stack *a, t_stack *b)
{
	int pivot;
	int pos;
	int *copy;

	copy = (int*)malloc(sizeof(int) * (a->top + 1));
	ft_memcpy(copy, a->stack, sizeof(int) * (a->top + 1));
	pivot = find_median(copy, a->top + 1);
	//sawp_top(a, 'a');
	while ((pos = find_next(a, pivot, 'I')) > -1)
	{
		// swap_top(a, 'a');

		// }
		// print_stack(a, 'a');
		// print_stack(b, 'b');
		//printf("~Value: %d <= Pivot: %d~\n", a->stack[pos], pivot);
		roto_next(a, pos, 'a');
		insort(a, b);
	}
	roto_next(a, find_min(a, a->top, 'I'), 'a');
	insort(a, b);
	// if (!is_ordered(a))
	// {
	// 	roto_next(a, find_min(a, a->top, 'I'), 'a');
	// 	insort(a, b);
	// }
	free(copy);
}
