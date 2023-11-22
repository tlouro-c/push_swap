/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:04:28 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/22 16:55:56 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
				swap_int(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
}
