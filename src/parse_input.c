/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 13:05:12 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 12:42:24 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int get_nlen(char **arr)
{
	int len;

	len = 0;
	while (arr[len])
		++len;
	return (len);
}

static	int check_dup(t_stack *s, int n)
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

static int valid_int(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (i == 0 && num[i] == '-')
			 ++i;
		else if (ft_isdigit(num[i]))
			++i;
		else
			return (0);
	}
	return (1);
}

/*
**parse int array given as multiple parameters
*/

int	parse_nparams(t_stack *a, t_stack *b, int argc, char **argv)
{
	int n;

	if (argc < 3)
		return (-1);
	init_stack(a, --argc);
	init_stack(b, argc);
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
	return (1);
}

/*
**arse int array given as a string with multiple numbers inside
*/

int parse_nstring(t_stack *a, t_stack *b, int argc, char *str)
{
	int n;
	int len;
	char **arr_int;

	if (argc > 2)
		return (-1);
	arr_int = ft_strsplit(str, ' ');
	len = get_nlen(arr_int);
	init_stack(a, len);
	init_stack(b, len);
	while (arr_int[--len])
	{
		if (!valid_int(arr_int[len]))
			break;
		n = ft_atoi(arr_int[len]);
		if (check_dup(a, n))
			break;
		push(a, n);
	}
	ft_arrdel(arr_int);
	if (len > -1)
		return (ft_error("Error", 2));
	return (1);
}
