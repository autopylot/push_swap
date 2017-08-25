/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:48:44 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 12:37:58 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc < 2)
		return (1);
	else if (parse_nstring(&a, &b, argc, argv[1]) == 0)
		return (1);
	else if (parse_nparams(&a, &b, argc, argv) == 0)
		return (1);
	if (is_ordered(&a) || is_sorted(&a))
		roto_next(&a, find_min(&a, a.top, 'I'), 'a');
	else if (a.top < 3)
		bubblesort(&a, 'a');
	else if (a.top < 5)
		quicksort(&a, &b);
	else
	{
		partial_sort(&a, &b);
		while (!is_empty(&b))
			insort(&b, &a, 'a');
		roto_next(&a, find_min(&a, a.top, 'I'), 'a');
	}
	return (0);
}
