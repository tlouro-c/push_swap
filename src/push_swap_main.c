/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:48:42 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/06 17:15:16 by tlouro-c         ###   ########.fr       */
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
	fill_stack_a(&stack_a, argc, argv);
	
	printf("Stack A: \n");
	print_stack(stack_a);

	printf("Stack B: \n");
	print_stack(stack_b);
	
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);

	printf("Stack A: \n");
	print_stack(stack_a);
	
	printf("Stack B: \n");
	print_stack(stack_b);

	rrr(&stack_a, &stack_b);
	printf("Stack A: \n");
	print_stack(stack_a);
	
	printf("Stack B: \n");
	print_stack(stack_b);

	stack_clear(&stack_a);
	stack_clear(&stack_b);
}
