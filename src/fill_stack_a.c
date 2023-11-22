/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:36:55 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/22 11:26:09 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(t_stack **stack, int argc, char *argv[])
{
	int	i;
	int	number;

	if (argv == NULL || argv[0] == NULL)
		exit(1);
	i = argc - 1;
	while (0 <= i)
	{
		if (valid_nr_check(argv[i]) == -1)
			error_exit_free_stack(stack);
		number = ft_atoi(argv[i], stack);
		push(stack, number);
		i--;
	}
}
