/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:53:48 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 11:11:13 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack *s, char c)
{
	if (s->top > 0)
	{
		if (s->top - 1 == find_min(s, s->top, 'I'))
			swap(s, c);
	}
}

/*
** rotate pos in stack to top
*/

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

/*
** rotate both stacks in same direction if possible
*/

void	roto_both(t_stack *a, int aloc, t_stack *b, int bloc)
{
	int atop;
	int btop;

	atop = a->stack[aloc];
	btop = b->stack[bloc];
	if (aloc < 1 || bloc < 1)
		return ;
	if (aloc >= (a->top / 2) && bloc >= (b->top / 2))
	{
		while (a->stack[a->top] != atop && b->stack[b->top] != btop)
		{
			rotate(a, 'r');
			rotate(b, 'q');
		}
	}
	else if (aloc < (a->top / 2) && bloc < (b->top / 2))
	{
		while (a->stack[a->top] != atop && b->stack[b->top] != btop)
		{
			rev_rotate(a, 'r');
			rev_rotate(b, 'q');
		}
	}
}
