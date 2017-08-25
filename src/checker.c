/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:06:09 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 12:47:44 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** error for maxint
*/

int	main(int argc, char **argv)
{
	int		n;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (1);
	else if (parse_nstring(&a, &b, argc, argv[1]) == 0)
		return (1);
	else if (parse_nparams(&a, &b, argc, argv) == 0)
		return (1);
	if (!read_instr(&a, &b))
		return (ft_error("Error", 2));
	if (is_sorted(&a) && is_empty(&b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
