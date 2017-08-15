/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 08:54:18 by wlin              #+#    #+#             */
/*   Updated: 2017/08/15 14:50:56 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	find_quartiles(t_stack *s, int *arr)
{
	int *copy;

	copy = (int*)malloc(sizeof(int) * (s->top + 1));
	ft_memcpy(copy, s->stack, sizeof(int) * (s->top + 1));
	arr[1] = find_median(copy, s->top + 1);
	arr[0] = copy[(s->top + 1) / 4];
	arr[2] = copy[(((s->top + 1) / 2) + s->top) / 2];
}

static	int get_quartile(int num, int *arr)
{
	if (num <= arr[0])
		return (1);
	else if (arr[0] < num && num <= arr[1])
		return (2);
	else if (arr[1] < num && num <= arr[2])
		return (3);
	else
		return (4);
}

// maintains the invariant that the biggest quartile has to be ontop
static	void roto_partial(t_stack *s1, int *part, char c)
{
	int q1;
	int q2;

	q1 = get_quartile(s1->stack[s1->top], part);
	q2 = get_quartile(s1->stack[s1->top - 1], part);
	if (s1->top < 1)
		return ;
	else if (q1 < q2)
		rotate(s1, c);
}

//partial sort a into b
void partial_sort(t_stack *s1, t_stack *s2)
{
	int arr_qt[3];
	int len;
	int *copy;

	find_quartiles(s1, arr_qt);
	len = s1->top + 1;
	while (len-- > -1)
	{
		if (s1->stack[s1->top] > arr_qt[0] && s1->stack[s1->top] <= arr_qt[2])
		{
			move(s1, s2 , 'b');
			roto_partial(s2, arr_qt, 'b');
		}
		else
			rotate(s1, 'a');
	}
	while (!is_empty(s1))
	{
		move(s1, s2 , 'b');
		roto_partial(s2, arr_qt, 'b');
	}
}
