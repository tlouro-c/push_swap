/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:50:18 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/22 11:55:02 by tlouro-c         ###   ########.fr       */
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
