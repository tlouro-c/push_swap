/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_essentials.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:53:07 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/22 00:35:44 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_stack	*iter;
	int		counter;

	if (stack == NULL)
		return ;
	counter = 0;
	iter = stack;
	while (iter != NULL)
	{
		if (counter++ == 0)
			printf("TOP:     % i\n", iter -> data);
		else
			printf("         % i\n", iter -> data);
		iter = iter -> next;
	}
}

void	print_list(t_list *list)
{
	t_list	*iter;
	int		counter;

	if (list == NULL)
		return ;
	counter = 0;
	iter = list;
	while (iter != NULL)
	{
		if (counter++ == 0)
			printf("TOP:     %s\n", iter -> cmd);
		else
			printf("         %s\n", iter -> cmd);
		iter = iter -> next;
	}
}
