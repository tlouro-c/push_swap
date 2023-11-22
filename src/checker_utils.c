/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:33:07 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/22 01:52:53 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	perform_cmd(t_list **list, t_stack **stack_a, t_stack **stack_b)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	tmp = *list;
	while (tmp != NULL)
	{
		exec_cmd(tmp -> cmd, stack_a, stack_b);
		tmp = tmp -> next;
	}
}

void	exec_cmd(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(cmd, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(cmd, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(cmd, "ss") == 0)
		checker_ss(stack_a, stack_b);
	else if (ft_strcmp(cmd, "pa") == 0)
		checker_pa(stack_a, stack_b);
	else if (ft_strcmp(cmd, "pb") == 0)
		checker_pb(stack_a, stack_b);
	else if (ft_strcmp(cmd, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(cmd, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(cmd, "rr") == 0)
		checker_rr(stack_a, stack_b);
	else if (ft_strcmp(cmd, "rra") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		reverse_rotate(stack_b);
	else
		checker_rrr(stack_a, stack_b);
}

void	clear_list(t_list **list)
{
	t_list	*next;
	t_list	*tmp;

	if (*list == NULL)
		return ;
	tmp = *list;
	while (tmp != NULL)
	{
		next = tmp -> next;
		free (tmp);
		tmp = next;
	}
	*list = NULL;
}

void	clear_stacks(t_stack **stack_a, t_stack **stack_b)
{
	stack_clear(stack_a);
	stack_clear(stack_b);
}
