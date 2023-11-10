/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:36:55 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/10 13:46:19 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	fill_stack_a(t_stack **stack, int argc, char *argv[])
{
	int	i;
	int	number;

	i = argc - 1;
	while (0 < i)
	{
		valid_nr_check(argv[i]);
		number = ft_atoi(argv[i], stack);
		push(stack, number);
		i--;
	}
}
