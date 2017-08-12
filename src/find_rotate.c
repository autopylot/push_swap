/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:53:48 by wlin              #+#    #+#             */
/*   Updated: 2017/08/11 17:15:44 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check a top and swap if top < top -1
void	swap_top(t_stack *s, char c)
{
	if (s->top > 0)
	{
		if (s->top - 1 == find_min(s, s->top, 'I'))
			swap(s, c);
	}
}

//rotates next num to be sorted to the top with least moves
void	roto_next(t_stack *s, int pos, char c)
{
	int next;

	next = s->stack[pos];
	if (pos >= (s->top / 2))
	{
		while (s->stack[s->top] != next)
			rotate(s, c);
	}
	else
		while (s->stack[s->top] != next)
			rev_rotate(s, c);
}

// rotate both stack if they can move in same directions
// before pushing pivot check if stack is ordered
void	roto_both(t_stack *a, int aloc, t_stack *b, bloc)
{
	if (aloc >= (a->top / 2) && bloc >= (b->top / 2))
}
