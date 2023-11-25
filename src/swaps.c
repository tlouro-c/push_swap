/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:35:02 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/25 14:57:54 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (list_len_till(stack, 3) < 2)
		return ;
	tmp1 = *stack;
	tmp2 = tmp1 -> next;
	tmp1 -> next = tmp2 -> next;
	tmp2 -> next = tmp1;
	*stack = tmp2;
}

void	sa(t_stack **stack)
{
	swap(stack);
	write (1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	swap(stack);
	write (1, "sb\n", 3);
}

void	ss(t_stack **stack1, t_stack **stack2)
{
	swap(stack1);
	swap(stack2);
	write(1, "ss\n", 3);
}

void	checker_ss(t_stack **stack1, t_stack **stack2)
{
	swap(stack1);
	swap(stack2);
	write(1, "ss\n", 3);
}
