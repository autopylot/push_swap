/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:37:59 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 11:10:38 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		sum_moves(int *tab)
{
	int i;
	int total;

	i = -1;
	total = 0;
	while (++i < 6)
		total += tab[i];
	return (total);
}

static	void	calc_short(int *tab)
{
	if (tab[0] <= tab[1])
		tab[1] = 0;
	else
		tab[0] = 0;
	if (tab[2] <= tab[3])
		tab[3] = 0;
	else
		tab[2] = 0;
	if (tab[0] > 0 && tab[2] > 0)
	{
		tab[4] = (tab[0] < tab[2] ? tab[0] : tab[2]);
		tab[0] = (tab[0] < tab[2] ? 0 : tab[0] - tab[2]);
		tab[2] = (tab[0] < tab[2] ? tab[2] - tab[0] : 0);
	}
	if (tab[1] > 0 && tab[3] > 0)
	{
		tab[5] = (tab[1] < tab[3] ? tab[1] : tab[3]);
		tab[1] = (tab[1] < tab[3] ? 0 : tab[1] - tab[3]);
		tab[3] = (tab[1] < tab[3] ? tab[3] - tab[1] : 0);
	}
}

static	int		*calc_moves(t_stack *s1, t_stack *s2, int ind)
{
	int i;
	int *tab;

	i = -1;
	tab = (int*)malloc(sizeof(int) * 7);
	ft_bzero(tab, sizeof(int) * 7);
	while (++i < 4)
	{
		if (i == 0)
			tab[i] = (s1->top - ind);
		else if (i == 1)
			tab[i] = (ind - 0 + 1);
		else if (i == 2)
			tab[i] = (s2->top - find_insert(s1->stack[ind], s2));
		else if (i == 3)
			tab[i] = (find_insert(s1->stack[ind], s2) - 0 + 1);
	}
	calc_short(tab);
	tab[6] = ind;
	return (tab);
}

int				find_optimal(t_stack *s1, t_stack *s2)
{
	int ind;
	int *min;
	int *temp;

	ind = s1->top;
	min = calc_moves(s1, s2, ind);
	while (--ind > -1)
	{
		temp = calc_moves(s1, s2, ind);
		if (sum_moves(temp) < sum_moves(min))
		{
			free(min);
			min = temp;
		}
		else
			free(temp);
	}
	ind = min[6];
	free(min);
	return (ind);
}
