/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:31:45 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/09 18:46:48 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	insert_end(stack, pop(stack));
}

void	ra(t_stack **stack)
{
	rotate(stack);
	write (1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	write (1, "rb\n", 3);
}

void	rr(t_stack **stack1, t_stack **stack2)
{
	rotate(stack1);
	rotate(stack2);
	write (1, "rr\n", 3);
}
