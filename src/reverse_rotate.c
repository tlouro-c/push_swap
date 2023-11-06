/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:47:56 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/06 17:02:08 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	push(stack, pop_end(stack));
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **stack1, t_stack **stack2)
{
	reverse_rotate(stack1);
	reverse_rotate(stack2);
	write (1, "rrr\n", 4);
}
