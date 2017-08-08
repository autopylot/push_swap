/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:43:58 by wlin              #+#    #+#             */
/*   Updated: 2017/08/07 15:07:41 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s, int n)
{
	s->top = -1;
	s->size = n;
	s->stack = (int*)malloc(sizeof(int) * n);
}

void	push(t_stack *s, int c)
{
	++s->top;
	s->stack[s->top] = c;
}

int		is_empty(t_stack *s)
{
	if (s->top == -1)
		return (1);
	else
		return (0);
}

int		pop(t_stack *s)
{
	int c;

	c = 0;
	if (s->top > -1)
	{
		c = s->stack[s->top];
		s->top = s->top - 1;
		return (c);
	}
	return (c);
}

int	swap(t_stack *s)
{
	int tmp;

	if (s->top > 0)
	{
		tmp = s->stack[s->top];
		s->stack[s->top] = s->stack[s->top - 1];
		s->stack[s->top - 1] = tmp;
	}
	return (1);
}

int	move(t_stack *a, t_stack *b)
{
	if (a->top > -1)
		push(b, pop(a));
	return (1);
}

int	rotate(t_stack *s)
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
	}
	return (1);
}

int rev_rotate(t_stack *s)
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
	}
	return (1);
}
