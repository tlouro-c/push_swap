/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:48:42 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/07 00:38:51 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		ordered_status;

	stack_a = NULL;
	stack_b = NULL;
	fill_stack_a(&stack_a, argc, argv);
	
	printf("Stack A: \n");
	print_stack(stack_a);
	
	ordered_status = ordered(&stack_a);	
	(void)ordered_status;
	stack_clear(&stack_a);
	stack_clear(&stack_b);
}
