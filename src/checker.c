/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:06:09 by wlin              #+#    #+#             */
/*   Updated: 2017/08/10 15:10:15 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int n;

	if (!(argc > 1))
		return (1);
	init_stack(&a, --argc);
	init_stack(&b, argc);
	if (argc == 2)
		
	else
	while (argc > 0)
	{
		if (!valid_int(argv[argc]))
			return (ft_error("Error", 2));
		n = ft_atoi(argv[argc]);
		if (check_dup(a, n))
			return (ft_error("Error", 2));
		push(&a, n);
		--argc;
	}
	if (!read_instr(&a, &b))
		return (ft_error("Error\n", 2));
	if (is_sorted(a) && is_empty(b))
		puts("OK");
	else
		puts("KO");
	return (0);
}
