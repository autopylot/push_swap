/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 11:28:37 by wlin              #+#    #+#             */
/*   Updated: 2017/08/16 11:39:00 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"

typedef struct s_stack
{
	int top;
	int size;
	int *stack;
}	t_stack;

void	init_stack(t_stack *s, int n);
void	push(t_stack *s, int c);
int		pop(t_stack *s);
int		swap(t_stack *s, char c);
int		move(t_stack *a, t_stack *b, char c);
int		rotate(t_stack *s, char c);
int		rev_rotate(t_stack *s, char c);
int		is_empty(t_stack *s);

int		ft_error(char const *s, int fd);
void 	print_stack(t_stack *s, char c);
int		exe_instr(char *instr, t_stack *a, t_stack *b);
int		read_instr(t_stack *a, t_stack *b);
int		parse_nparams(t_stack *a, t_stack *b, int argc, char **argv);
int		parse_nstring(t_stack *a, t_stack *b, char *str);

void 	partial_sort(t_stack *s1, t_stack *s2);
void	insort(t_stack *s1, t_stack *s2, char c);
void	bubblesort(t_stack *s, char c);
void	quicksort(t_stack *a, t_stack *b);

void 	swap_top(t_stack *s, char c);
int 	is_ordered(t_stack *s);
int 	is_sorted(t_stack *s);
void	roto_next(t_stack *s, int pos, char c);
void	roto_both(t_stack *a, int aloc, t_stack *b, int bloc);

int		find_optimal(t_stack *s1, t_stack *s2);
int		find_ind(t_stack *s, int nbr);
int		find_max(t_stack *s, int len, char c);
int		find_min(t_stack *s, int size, char c);
int		find_next(t_stack *s, int pivot, char c);
int 	find_median(int *arr, int len);
int		find_insert(int n, t_stack *s);

#endif
