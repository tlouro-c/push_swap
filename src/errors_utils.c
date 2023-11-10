/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:14:18 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/10 12:29:19 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dup_check(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;
	int		counter;

	current = *stack;
	while (current != NULL)
	{
		counter = 0;
		tmp = *stack;
		while (tmp != NULL)
		{
			if ((current -> data) == (tmp -> data))
				counter++;
			tmp = tmp -> next;
		}
		if (counter > 1)
			error_exit();
		current = current -> next;
	}
}

void	error_exit(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	stack_empty(void)
{
	write (2, "Nothing to be deleted!\n", 23);
	exit(1);
}

void	valid_nr_check(char *s)
{
	int	i;

	if (s[0] != '+' && s[0] != '-' 
		&& ft_isdigit(s[0]) == 0 && space(s[0]) == 0)
		error_exit();
	i = 0;
	while (space(s[i]))
		i++;
	if (s[i] != '+' && s[i] != '-' && ft_isdigit(s[i]) == 0)
		error_exit();
	if (s[i] != '+' || s[i] != '-')
		i++;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 0)
			error_exit();
		i++;
	}
	return ;
}
