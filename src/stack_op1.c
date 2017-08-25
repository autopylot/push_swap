/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:43:58 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 11:50:25 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s, int n)
{
	s->top = -1;
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
		--s->top;
		return (c);
	}
	return (c);
}

int		swap(t_stack *s, char c)
{
	int tmp;

	if (s->top > 0)
	{
		tmp = s->stack[s->top];
		s->stack[s->top] = s->stack[s->top - 1];
		s->stack[s->top - 1] = tmp;
		if (c == 'a')
			ft_putstr("sa\n");
		else if (c == 'b')
			ft_putstr("sb\n");
		else if (c == 's')
			ft_putstr("ss\n");
	}
	return (1);
}
