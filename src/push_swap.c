/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:48:44 by wlin              #+#    #+#             */
/*   Updated: 2017/08/07 14:54:03 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check a top and swap if top < top -1
void check_top(t_stack *s)
{
	if (s->top > 0)
	{
		if (s->stack[s->top - 1] < s->stack[s->top])
			swap(s);
	}
}

//check if stack is ordered and just needed to be rotated
int is_ordered(t_stack *s)
{
	int min_loc;
	int n;

	n = s->top;
	min_loc = min_stack(s, s->top);
	while (n-- > 0)
	{
		if (min_loc == 0)
		{
			if (s->stack[min_loc] < s->stack[s->top])
				min_loc = s->top;
			else
				return (0);
		}
		else
		{
			if (s->stack[min_loc] < s->stack[min_loc - 1])
				--min_loc;
			else
				return (0);
		}
	}
	return (1);
}

//rotoates element at pos to top
void roto_top(t_stack *s, int n, char c)
{
	int i;

	i = -1;
	if (c == 'T')
	{
		while (++i < n)
			rotate(s);
	}
	if (c == 'B')
		while (++i < n)
			rev_rotate(s);
}

int get_numbers(t_stack *a, t_stack *b, int argc, char **argv)
{
	int n;

	while (argc > 0)
	{
		if (!valid_int(argv[argc]))
			return (ft_error("Error", 2));
		n = ft_atoi(argv[argc]);
		if (check_dup(a, n))
			return (ft_error("Error", 2));
		push(a, n);
		--argc;
	}
	return (0);
}

/*
Program driver
1.	check size of a->top
2.	if a->top > 10 then run qsort until a->top < 10
3	if a->top < 10 bubble sort until stack a is ordererd
4.	if stack a is ordered rotate min to top
5. 	if stack b is not empty push b back.
*/
int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int n;

	if (!(argc > 1))
		return (0);
	init_stack(&a, --argc);
	init_stack(&b, argc);
	if (get_numbers(&a, &b, argc, argv))
		return (1);
	if (a.top < 9)
		bubblesort(&a);
	print_stack(&a, 'a');
	print_stack(&b, 'b');
	printf("Sorted: %d\n", is_sorted(&a));
	return (0);
}
