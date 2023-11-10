/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:48:42 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/10 13:46:11 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		argc = count_words(argv[1]) + 1;
		argv = split(argv[1]);
	}
	fill_stack_a(&stack_a, argc, argv);
	dup_check(&stack_a);
	print_stack(stack_a);
	(void)stack_b;
	return (0);
}
