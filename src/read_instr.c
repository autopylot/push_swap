/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 10:36:16 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 12:50:36 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exe_instr(char *instr, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(instr, "ss"))
		return (exe_instr("sa", a, b) + exe_instr("sb", a, b));
	else if (!ft_strcmp(instr, "sa"))
		return (swap(a, 'q'));
	else if (!ft_strcmp(instr, "sb"))
		return (swap(b, 'q'));
	else if (!ft_strcmp(instr, "pa"))
		return (move(b, a, 'q'));
	else if (!ft_strcmp(instr, "pb"))
		return (move(a, b, 'q'));
	else if (!ft_strcmp(instr, "rr"))
		return (exe_instr("ra", a, b) + exe_instr("rb", a, b));
	else if (!ft_strcmp(instr, "ra"))
		return (rotate(a, 'q'));
	else if (!ft_strcmp(instr, "rb"))
		return (rotate(b, 'q'));
	else if (!ft_strcmp(instr, "rrr"))
		return (exe_instr("rra", a, b) + exe_instr("rrb", a, b));
	else if (!ft_strcmp(instr, "rra"))
		return (rev_rotate(a, 'q'));
	else if (!ft_strcmp(instr, "rrb"))
		return (rev_rotate(b, 'q'));
	return (0);
}

int	read_instr(t_stack *a, t_stack *b)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (!exe_instr(line, a, b))
			return (0);
		ft_strdel(&line);
	}
	return (1);
}
