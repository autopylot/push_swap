/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 10:36:16 by wlin              #+#    #+#             */
/*   Updated: 2017/08/10 14:18:24 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	return (1);
}

void print_stack(t_stack *s, char c)
{
	int i = s->top;
	while (i > -1)
	{
		printf("[%d] %d\n", i, s->stack[i]);
		if (i == 0)
			printf("[Stack %c]\n", c);
		--i;
	}
}

int valid_int(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (i == 0 && !ft_isdigit(num[i]))
		{
			if (num[i] == '-')
			 	++i;
			else
				return (0);
		}
		else if (ft_isdigit(num[i]))
			++i;
		else
			return (0);
	}
	return (1);
}

int check_dup(t_stack *s, int n)
{
	int i;

	i = 0;
	if (s->top > -1)
	{
		while (i <= s->top)
		{
			if (s->stack[i++] == n)
				return (1);
		}
		return (0);
	}
	return (0);
}

int exe_instr(char *instr, t_stack *a, t_stack *b)
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
	else if  (!ft_strcmp(instr, "rr"))
		return (exe_instr("ra", a, b) + exe_instr("rb", a, b));
	else if (!ft_strcmp(instr, "ra"))
		return (rotate(a, 'q'));
	else if (!ft_strcmp(instr, "rb"))
		return (rotate(b, 'q'));
	else if  (!ft_strcmp(instr, "rrr"))
		return (exe_instr("rra", a, b) + exe_instr("rrb", a, b));
	else if (!ft_strcmp(instr, "rra"))
		return (rev_rotate(a, 'q'));
	else if (!ft_strcmp(instr, "rrb"))
		return (rev_rotate(b, 'q'));
	return (0);
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


int read_instr(t_stack *a, t_stack *b)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (!exe_instr(line, a, b))
			return (0);
		print_stack(a, 'a');
		print_stack(b, 'b');
		ft_strdel(&line);
	}
	return (1);
}
