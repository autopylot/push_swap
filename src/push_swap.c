/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:48:44 by wlin              #+#    #+#             */
/*   Updated: 2017/08/11 17:15:47 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		if (!parse_nstring(&a, &b, argv[1]))
			return (1);
	}
	else
	{
		init_stack(&a, --argc);
		init_stack(&b, argc);
		if (!parse_nparams(&a, &b, argc, argv))
			return (1);
	}
	while (!is_sorted(&a))
	{
		if (a.top > 5)
			quicksort(&a, &b);
		else
		{
			


			roto_next(&b, find_max(&b, b.top, 'I'), 'b');
			while (!is_empty(&b))
				move(&b, &a, 'a');
			break ;
		}
	}
	//print_stack(&a, 'a');
	//printf("Sorted: %d\n", is_sorted(&a));
	return (0);
}
