/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 11:28:37 by wlin              #+#    #+#             */
/*   Updated: 2017/08/02 13:47:11 by wlin             ###   ########.fr       */
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
int		swap(t_stack *s);
int		move(t_stack *a, t_stack *b);
int		rotate(t_stack *s);
int		rev_rotate(t_stack *s);
int		is_empty(t_stack *s);
int		exe_instr(char *instr, t_stack *a, t_stack *b);
int		read_instr(t_stack *a, t_stack *b);
int		check_dup(t_stack *s, int n);
int		valid_int(char *num);
#endif
