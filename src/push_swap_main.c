/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:48:42 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/27 16:35:56 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	argv[1] = argjoin(argc, argv);
	argc = count_words(argv[1]);
	argv = split(argv[1]);
	fill_stack_a(&stack_a, argc, argv);
	dup_check(&stack_a, argc, argv);
	if (!ordered(stack_a))
		algorithm_base(&stack_a, &stack_b);
	clear_loop(argv, argc);
	stack_clear(&stack_a);
	return (0);
}
