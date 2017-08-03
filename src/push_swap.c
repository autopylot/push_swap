/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:48:44 by wlin              #+#    #+#             */
/*   Updated: 2017/08/03 14:56:47 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	set_mxind(t_mxind *smax, int ind, int n)
{
	smax->max = n;
	smax->ind = ind;
}

// find max in b stack if n > b return ind, else if ind - 1 check if n > stack[top] if not --top
int				find_binsert(int n, t_stack *s)
{
	int		i;
	t_mxind	smax;

	i = s->top;
	set_mxind(&smax, s->top, s->stack[s->top]);
	while (--i > -1)
	{
		if (s->stack[i] > smax.max)
			set_mxind(&smax, i, s->stack[i]);
	}
	while (smax.ind)
	{
		if (n > s->stack[smax.ind])
			return (smax.ind);
		--smax.ind
	}
	return (s->top);
}

// find sorted for b push
void psort_b(t_stack *a, t_stack *b)
{
	int insert;

	if (b->top < 1)
		return (move(a, b)); // print instr
	insert = find_binsert(a->stack[a->top], b);
	if (insert >= (b->top / 2))
		//rot up
	else
		//rot down


}

int push_swap(t_stack *a, t_stack *b)
{
	int pivot;
	int low;
	int high;

	while (is_sorted(a) && is_empty(b))
	{
		high = 0;
		low = a->top;
		pivot = a->top / 2;

		while (a->stack[low] < a->stack[pivot])
			//push and sort lower into b


	}
}




int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int n;

	if (!(argc > 1))
		return (0);
	init_stack(&a, --argc);
	init_stack(&b, argc);
	while (argc > 0)
	{
		if (!valid_int(argv[argc]))
			return (ft_error("Error", 2));
		n = ft_atoi(argv[argc]);
		if (check_dup(&a, n))
			return (ft_error("Error", 2));
		push(&a, n);
		--argc;
	}



	return (0);
}
