/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:42:06 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/21 11:27:29 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_base(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = list_len_till(stack_a, 4);
	if (len <= 1)
		return ;
	else if (len == 2)
	{
		if (first(*stack_a) > second(*stack_a))
			sa(stack_a);
		return ;
	}
	else if (len == 3)
		mini_sort(stack_a);
	else
		algorithm(stack_a, stack_b);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	cheapest;
	t_min	min;

	while (list_len_till(stack_a, 4) > 3)
		pb(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		get_targets(*stack_a, *stack_b);
		cheapest = get_costs(*stack_a, *stack_b);
		if (cheapest.path == cheapest.path_target)
			rotate_same_path(stack_a, stack_b, cheapest);
		move_cheapest(stack_a, stack_b, cheapest);
	}
	min.value = INT_MAX;
	min.path = ROTATE;
	last_rotates(stack_a, min);
}

void	get_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		current_dif;
	int		new_dif;

	tmpb = stack_b;
	while (tmpb != NULL)
	{
		tmpb -> target = INT_MAX;
		tmpa = stack_a;
		while (tmpa != NULL)
		{
			current_dif = tmpb -> target - tmpb -> data;
			new_dif = tmpa -> data - tmpb -> data;
			if (new_dif > 0 && new_dif < abs(current_dif))
				tmpb -> target = tmpa -> data;
			tmpa = tmpa -> next;
		}
		if (tmpb -> target == INT_MAX)
			tmpb -> target = find_min(stack_a);
		tmpb = tmpb -> next;
	}
}

void	rotate_same_path(t_stack **stack_a, t_stack **stack_b, t_stack cheap)
{
	while (first(*stack_a) != cheap.target 
		&& first(*stack_b) != cheap.data)
	{
		if (cheap.path == ROTATE)
			rr(stack_a, stack_b);
		else
			rrr(stack_a, stack_b);
	}
}

void	move_cheapest(t_stack **stack_a, t_stack **stack_b, t_stack cheapest)
{
	while (first(*stack_a) != cheapest.target)
	{
		if (cheapest.path_target == ROTATE)
			ra(stack_a);
		else
			rra(stack_a);
	}
	while (first(*stack_b) != cheapest.data)
	{
		if (cheapest.path == ROTATE)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}
