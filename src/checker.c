/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:06:09 by wlin              #+#    #+#             */
/*   Updated: 2017/08/11 15:56:18 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int n;

	if (argc < 2)
		return (1);
	if (argc == 2)
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
	if (!read_instr(&a, &b))
		return (ft_error("Error", 2));
	if (is_sorted(&a) && is_empty(&b))
		puts("OK");
	else if (is_ordered(&a))
		puts("ordered");
	else
		puts("KO");
	return (0);
}
