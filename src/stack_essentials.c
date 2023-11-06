/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_essentials.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:36:48 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/06 17:21:47 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		stack_empty();
	new -> data = number;
	new -> next = *stack;
	*stack = new;
}

int	pop(t_stack **stack)
{
	t_stack	*tmp;
	int		popped;

	if (*stack == NULL)
		stack_empty();
	tmp = *stack;
	popped = tmp -> data;
	*stack = tmp -> next;
	free(tmp);
	return (popped);
}

void	insert_end(t_stack **stack, int number)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		error_exit();
	new -> data = number;
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

int	pop_end(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tofree;
	int		popped;

	if (*stack == NULL)
		stack_empty();
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
}
