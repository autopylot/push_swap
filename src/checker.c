/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:06:09 by wlin              #+#    #+#             */
/*   Updated: 2017/08/07 12:46:27 by wlin             ###   ########.fr       */
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
			printf("Stack %c\n", c);
		--i;
	}
}

int valid_int(char *num)
{
	while (*num)
	{
		if (ft_isdigit(*num) || *num == '-')
			++num;
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

int is_sorted(t_stack *s)
{
	int i;

	i = s->top;
	if (s->top == 0)
		return (1);
	while (i > 0)
	{
		if (!(s->stack[i] < s->stack[i - 1]))
			return (0);
		--i;
	}
	return (1);
}

int exe_instr(char *instr, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(instr, "ss"))
		return (exe_instr("sa", a, b) + exe_instr("sb", a, b));
	else if (!ft_strcmp(instr, "sa"))
		return (swap(a));
	else if (!ft_strcmp(instr, "sb"))
		return (swap(b));
	else if (!ft_strcmp(instr, "pa"))
		return (move(b, a));
	else if (!ft_strcmp(instr, "pb"))
		return (move(a, b));
	else if  (!ft_strcmp(instr, "rr"))
		return (exe_instr("ra", a, b) + exe_instr("rb", a, b));
	else if (!ft_strcmp(instr, "ra"))
		return (rotate(a));
	else if (!ft_strcmp(instr, "rb"))
		return (rotate(b));
	else if  (!ft_strcmp(instr, "rrr"))
		return (exe_instr("rra", a, b) + exe_instr("rrb", a, b));
	else if (!ft_strcmp(instr, "rra"))
		return (rev_rotate(a));
	else if (!ft_strcmp(instr, "rrb"))
		return (rev_rotate(b));
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

// int main(int argc, char **argv)
// {
// 	t_stack a;
// 	t_stack b;
// 	int n;
//
// 	if (!(argc > 1))
// 		return (0);
// 	init_stack(&a, --argc);
// 	init_stack(&b, argc);
// 	while (argc > 0)
// 	{
// 		if (!valid_int(argv[argc]))
// 			return (ft_error("Error", 2));
// 		n = ft_atoi(argv[argc]);
// 		if (check_dup(&a, n))
// 			return (ft_error("Error", 2));
// 		push(&a, n);
// 		--argc;
// 	}
// 	if (!read_instr(&a, &b))
// 		return (ft_error("Error\n", 2));
// 	if (is_sorted(&a) && is_empty(&b))
// 		puts("OK");
// 	else
// 		puts("KO");
// 	return (0);
// }
