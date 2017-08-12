/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 13:05:12 by wlin              #+#    #+#             */
/*   Updated: 2017/08/11 15:37:27 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int get_nlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			++len;
			while (ft_isdigit(*str))
				++str;
		}
		else
			++str;
	}
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

static	int valid_str(char *str)
{
	while (*str)
	{
		if (*str == '-')
		{
			++str;
			if (!ft_isdigit(*str))
				return (0);
		}
		else if (ft_isdigit(*str))
		{
			++str;
			if (*str == '\0')
				return (1);
			else if (!ft_isdigit(*str) && *str != ' ')
				return (0);
		}
		else if (*str == ' ')
		{
			++str;
			if (!ft_isdigit(*str) && *str != '-')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

//parse int array given as multiple parameters
int	parse_nparams(t_stack *a, t_stack *b, int argc, char **argv)
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
	return (1);
}

//parse int array given as a string with multiple numbers inside
int parse_nstring(t_stack *a, t_stack *b, char *str)
{
	int i;
	int n;
	int len;

	i = ft_strlen(str) - 1;
	len = get_nlen(str);
	init_stack(a, len);
	init_stack(b, len);
	if(!valid_str(str))
		return (ft_error("Error", 2));
	while (str[i])
	{
		while ((ft_isdigit(str[i]) || str[i] == '-') && str[i] && i != 0)
			--i;
		n = ft_atoi(str + i);
		--i;
		if (check_dup(a, n))
			return (ft_error("Error", 2));
		push(a, n);
	}
	return (1);
}
