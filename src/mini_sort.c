/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:44:44 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/20 19:24:20 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first(t_stack *stack)
{
	return (stack -> data);
}

int	second(t_stack *stack)
{
	return (stack -> next -> data);
}

int	third(t_stack *stack)
{
	return (stack -> next -> next -> data);
}

void	mini_sort(t_stack **stack)
{
	if (first (*stack) < second(*stack) && second(*stack) < third(*stack))
		return ;
	else if (third(*stack) < second(*stack) && third(*stack) > first(*stack))
	{
		rra(stack);
		sa(stack);
	}
	else if (first(*stack) > second(*stack) && second(*stack) > third(*stack))
	{
		ra(stack);
		sa(stack);
	}
	else if (first(*stack) > third(*stack) && second(*stack) < third(*stack))
		ra(stack);
	else if (first(*stack) > third(*stack) && first(*stack) < second(*stack))
		rra(stack);
	else
		sa(stack);
}
