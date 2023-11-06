/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:11:08 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/06 17:20:16 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	top_b;

	top_b = pop(stack_b);
	push(stack_a, top_b);
	write (1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	top_a;

	top_a = pop(stack_a);
	push(stack_b, top_a);
	write (1, "pb\n", 3);
}
