/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:50:18 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/25 14:56:01 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	min = INT_MAX;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp -> data < min)
			min = tmp -> data;
		tmp = tmp -> next;
	}
	return (min);
}

int	ordered(t_stack *stack_a)
{
	t_stack	*tmp;
	int		save;

	if (stack_a == NULL)
		return (1);
	save = stack_a -> data;
	tmp = stack_a;
	while (tmp != NULL)
	{
		if (tmp -> data < save)
			return (0);
		save = tmp -> data;
		tmp = tmp -> next;
	}
	return (1);
}

void	a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_mid	info;
	int		mid_point;

	mid_point = mid(*stack_a);
	info = (below_mid(*stack_a, mid_point, list_len_till(stack_a, INT_MAX)));
	while (list_len_till(stack_a, 4) > 3)
	{
		if (first(*stack_a) < mid_point)
		{
			pb(stack_a, stack_b);
			info.count_below--;
		}
		else if (info.count_below > 0 && info.path == ROTATE)
			ra(stack_a);
		else if (info.count_below > 0 && info.path == REVERSE_ROTATE)
			rra(stack_a);
		else
			pb(stack_a, stack_b);
	}
}

int	mid(t_stack *stack)
{
	t_stack	*tmp;
	int		*array;
	int		i;
	int		len;

	len = list_len_till(&stack, INT_MAX);
	array = (int *)malloc(len * sizeof(int));
	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		array[i++] = tmp -> data;
		tmp = tmp -> next;
	}
	bubble_sort(array, len);
	return (array[len / 2]);
}

t_mid	below_mid(t_stack *stack, int mid, int size)
{
	t_stack	*tmp;
	t_mid	info;
	int		pos;
	int		counter_1half;
	int		counter_2half;

	counter_1half = 0;
	counter_2half = 0;
	pos = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp -> data < mid && pos < size / 2)
			counter_1half++;
		else if (tmp -> data < mid && pos >= size / 2)
			counter_2half++;
		pos++;
		tmp = tmp -> next;
	}
	if (counter_1half >= counter_2half)
		info.path = ROTATE;
	else 
		info.path = REVERSE_ROTATE;
	info.count_below = counter_1half + counter_2half;
	return (info);
}
