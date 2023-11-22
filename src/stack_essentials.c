/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_essentials.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:36:48 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/22 20:43:37 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, long number)
{
	t_stack	*new;

	if (number == INT_MAX + (long)1)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new -> data = (int)number;
	new -> next = *stack;
	*stack = new;
}

long	pop(t_stack **stack)
{
	t_stack	*tmp;
	long	popped;

	if (*stack == NULL)
		return (INT_MAX + (long)1);
	tmp = *stack;
	popped = tmp -> data;
	*stack = tmp -> next;
	free(tmp);
	return (popped);
}

void	insert_end(t_stack **stack, long number)
{
	t_stack	*new;
	t_stack	*tmp;

	if (number == INT_MAX + (long)1)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		error_exit();
	new -> data = (int)number;
	new -> next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		tmp -> next = new;
	}
}

long	pop_end(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tofree;
	long	popped;

	if (*stack == NULL)
		return (INT_MAX + (long)1);
	tmp = *stack;
	while (tmp -> next -> next != NULL)
		tmp = tmp -> next;
	tofree = tmp -> next;
	popped = tofree -> data;
	free (tofree);
	tmp -> next = NULL;
	return (popped);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (tmp != NULL)
	{
		next = tmp -> next;
		free (tmp);
		tmp = next;
	}
	*stack = NULL;
}
