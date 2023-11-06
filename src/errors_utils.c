/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:14:18 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/06 16:55:17 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		&& ft_isdigit(s[0]) == 0 && ft_isspace(s[0]) == 0)
		error_exit();
	i = 0;
	while (ft_isspace(s[i]))
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
