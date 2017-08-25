/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:35:08 by wlin              #+#    #+#             */
/*   Updated: 2017/08/25 11:09:34 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap_ele(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

static	int		partition(int *arr, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap_ele(&arr[i], &arr[j]);
		}
		++j;
	}
	swap_ele(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void		qiksort(int *arr, int start, int end)
{
	int part;

	if (start < end)
	{
		part = partition(arr, start, end);
		qiksort(arr, start, part - 1);
		qiksort(arr, part + 1, end);
	}
}

int				find_median(int *arr, int len)
{
	qiksort(arr, 0, len - 1);
	return (arr[len / 2]);
}
