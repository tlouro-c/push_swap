/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:49:32 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/22 20:52:20 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len_till(t_stack **stack, int max)
{
	int		counter;
	t_stack	*tmp;

	counter = 0;
	tmp = *stack;
	while (tmp != NULL && counter < max)
	{
		tmp = tmp -> next;
		counter++;
	}
	return (counter);
}

t_stack	get_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	cheapest;

	get_data_cost(stack_b);
	get_target_cost(stack_a, stack_b);
	cheapest.total_cost = INT_MAX;
	tmp = stack_b;
	while (tmp != NULL)
	{
		tmp -> total_cost = tmp -> cost + tmp -> cost_target;
		if (tmp -> total_cost < cheapest.total_cost)
		{
			cheapest.total_cost = tmp -> total_cost;
			cheapest.path = tmp -> path;
			cheapest.path_target = tmp -> path_target;
			cheapest.target = tmp -> target;
			cheapest.data = tmp -> data;
		}
		tmp = tmp -> next;
	}
	return (cheapest);
}

void	get_data_cost(t_stack *stack_b)
{
	t_stack		*tmp1;
	t_stack		*tmp2;
	int			len;

	len = list_len_till(&stack_b, INT_MAX);
	tmp1 = stack_b;
	while (tmp1 != NULL)
	{
		tmp1 -> cost = 0;
		tmp1 -> path = ROTATE;
		tmp2 = stack_b;
		while (tmp2 -> data != tmp1 -> data)
		{
			tmp1 -> cost++;
			tmp2 = tmp2 -> next;
		}
		if (tmp1 -> cost > len / 2)
		{
			tmp1 -> path = REVERSE_ROTATE;
			tmp1 -> cost = len - tmp1 ->cost;
		}
		tmp1 = tmp1 -> next;
	}
}

void	get_target_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*tmp1;
	t_stack		*tmp2;
	int			len;

	len = list_len_till(&stack_a, INT_MAX);
	tmp1 = stack_b;
	while (tmp1 != NULL)
	{
		tmp1 -> cost_target = 0;
		tmp1 -> path_target = ROTATE;
		tmp2 = stack_a;
		while (tmp2 -> data != tmp1 -> target)
		{
			tmp1 -> cost_target++;
			tmp2 = tmp2 -> next;
		}
		if (tmp1 -> cost_target > len / 2)
		{
			tmp1 -> path_target = REVERSE_ROTATE;
			tmp1 -> cost_target = len - tmp1 -> cost_target;
		}
		tmp1 = tmp1 -> next;
	}
}

void	last_rotates(t_stack **stack_a, t_min *min, int cost)
{
	t_stack	*tmp;
	int		len;

	len = list_len_till(stack_a, INT_MAX);
	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (tmp -> data < min -> value)
		{
			min -> value = tmp -> data;
			min -> cost = cost;
		}
		cost++;
		tmp = tmp -> next;
	}
	if (min -> cost > len / 2)
		min -> path = REVERSE_ROTATE;
	while (first(*stack_a) != min -> value)
	{
		if (min -> path == ROTATE)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
