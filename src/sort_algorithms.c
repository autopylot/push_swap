/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:02:40 by wlin              #+#    #+#             */
/*   Updated: 2017/08/10 14:07:02 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insort(t_stack *a, t_stack *b)
{
	int ins_pos;
	int	ins_num;

	//printf("~Moving %d to stack b~\n", a->stack[a->top]);
	if (b->top < 1)
		move(a, b, 'b');
	else
	{
		ins_pos = find_insert(a->stack[a->top], b);
		roto_next(b, ins_pos, 'b');
		move(a, b, 'b');
	}
	//print_stack(a, 'a');
	//print_stack(b, 'b');
}

void	quicksort(t_stack *a, t_stack *b)
{
	int pivot;
	int pos;
	int *copy;

	copy = (int*)malloc(sizeof(int) * (a->top + 1));
	ft_memcpy(copy, a->stack, sizeof(int) * (a->top + 1));
	pivot = find_median(copy, a->top + 1);

	// print_stack(a, 'a');
	// check_top(a, 'a');

	while ((pos = next_sort(a, pivot, 'I')) > -1)
	{
		// print_stack(a, 'a');
		// print_stack(b, 'b');
		//printf("~Value: %d <= Pivot: %d~\n", a->stack[pos], pivot);
		roto_next(a, pos, 'a');
		insort(a, b);
	}
	roto_next(a, find_min(a, a->top, 'I'), 'a');
	insort(a, b);
	free(copy);
}
