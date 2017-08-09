/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:02:40 by wlin              #+#    #+#             */
/*   Updated: 2017/08/09 13:57:53 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int quickselect(int *arr, int size, int k)
{
	int from = 0;
	int to = size - 1;
	int r = 0;
	int w = 0;
	int mid = 0;
	int tmp = 0;

	while (from < to)
	{
		r = from;
		w = to;
		mid = arr[(r + w) / 2];
		while (r < w)
		{
			if (arr[r] >= mid)
			{
				tmp = arr[w];
				arr[w] = arr[r];
				arr[r] = tmp;
				w--;
			}
			else
				r++;
		}
		if (arr[r] > mid)
			r--;
		if (k <= r)
			to = r;
		else
			from = r + 1;
	}
	return (arr[k]);
}

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

	pivot = quickselect(a->stack, a->top, (a->top / 2) - 1);
	//check_top(a, 'a');
	while ((pos = next_sort(a, pivot, 'I')) > -1)
	{
		//print_stack(a, 'a');
		//printf("~Value: %d <= Pivot: %d~\n", a->stack[pos], pivot);
		roto_next(a, pos, 'a');
		insort(a, b);
	}
}
