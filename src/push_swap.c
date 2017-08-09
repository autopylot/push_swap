/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:48:44 by wlin              #+#    #+#             */
/*   Updated: 2017/08/09 13:56:55 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int get_numbers(t_stack *a, t_stack *b, int argc, char **argv)
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

	if (!(argc > 1))
		return (0);
	init_stack(&a, --argc);
	init_stack(&b, argc);
	if (get_numbers(&a, &b, argc, argv))
		return (1);
	while (a.top > -1)
	{
		if (a.top > 1)
			quicksort(&a, &b);
		else
		{
			if (a.stack[a.top] > a.stack[a.top - 1])
				swap(&a, 'a');
			while (!is_empty(&b))
				move(&b, &a, 'a');
			break ;
		}
	}
	// print_stack(&a, 'a');
	// print_stack(&b, 'b');
	//printf("Sorted: %d\n", is_sorted(&a));
	return (0);
}
