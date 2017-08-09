/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:43:58 by wlin              #+#    #+#             */
/*   Updated: 2017/08/09 13:01:42 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move(t_stack *a, t_stack *b, char c)
{
	if (a->top > -1)
	{
		push(b, pop(a));
		if (c == 'a')
			ft_putstr("pa\n");
		else if (c == 'b')
			ft_putstr("pb\n");
	}
	return (1);
}

int	rotate(t_stack *s, char c)
{
	int i;
	int tmp;

	i = s->top;
	if (s->top > 0)
	{
		tmp = s->stack[s->top];
		while (--i > -1)
			ft_memmove(s->stack + (i + 1), s->stack + i, sizeof(int));
		s->stack[0] = tmp;
		if (c == 'a')
			ft_putstr("ra\n");
		else if (c == 'b')
			ft_putstr("rb\n");
		else if (c == 'r')
			ft_putstr("rr\n");
	}
	return (1);
}

int rev_rotate(t_stack *s, char c)
{
	int i;
	int tmp;

	i = -1;
	if (s->top > 0)
	{
		tmp = s->stack[0];
		while (++i < s->top)
			ft_memmove(s->stack + i, s->stack + i + 1, sizeof(int));
		s->stack[s->top] = tmp;
		if (c == 'a')
			ft_putstr("rra\n");
		else if (c == 'b')
			ft_putstr("rrb\n");
		else if (c == 'r')
			ft_putstr("rrr\n");
	}
	return (1);
}
