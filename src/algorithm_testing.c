/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:27:47 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/07 00:41:10 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ordered(t_stack **stack)
{
	t_stack	*current;
	t_stack *next;

	if (*stack == NULL)
	{
		write(1, "Ordered\n", 8);
		return (1);
	}
	current = *stack;
	while (current -> next != NULL)
	{
		next = current -> next;
		if ((current -> data) > (next -> data))
		{
			write(1, "Not ordered\n", 12);
			return (0);
		}
		current = next;
	}
	write(1, "Ordered\n", 8);
	return (1);
}
