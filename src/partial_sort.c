/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 08:54:18 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 11:30:29 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	find_iqrange(t_stack *s, int *arr)
{
	int			*copy;

	copy = (int*)malloc(sizeof(int) * (s->top + 1));
	ft_memcpy(copy, s->stack, sizeof(int) * (s->top + 1));
	arr[1] = find_median(copy, s->top + 1);
	arr[0] = copy[(s->top + 1) / 4];
	arr[2] = copy[(((s->top + 1) / 2) + s->top) / 2];
	free(copy);
}

static	int		get_iq(int num, int *arr)
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

static	void	roto_partial(t_stack *s1, int *arr, char c)
{
	int			q1;
	int			q2;

	q1 = get_iq(s1->stack[s1->top], arr);
	q2 = get_iq(s1->stack[s1->top - 1], arr);
	if (s1->top < 1)
		return ;
	else if (q1 < q2)
		rotate(s1, c);
}

void			partial_sort(t_stack *s1, t_stack *s2)
{
	int			iqrange[3];
	int			len;

	find_iqrange(s1, iqrange);
	len = s1->top + 1;
	while (len-- > -1)
	{
		if (s1->stack[s1->top] > iqrange[0] && s1->stack[s1->top] <= iqrange[2])
		{
			move(s1, s2, 'b');
			roto_partial(s2, iqrange, 'b');
		}
		else
			rotate(s1, 'a');
	}
	while (!is_empty(s1))
	{
		move(s1, s2, 'b');
		roto_partial(s2, iqrange, 'b');
	}
}
