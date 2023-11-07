/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_essentials.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:53:07 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/07 12:23:23 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_stack	*iter;
	int		counter;

	counter = 0;
	iter = stack;
	while (iter != NULL)
	{
		if (counter++ == 0)
			printf("Top: % i\n", iter -> data);
		else
			printf("     % i\n", iter -> data);
		iter = iter -> next;
	}
}
