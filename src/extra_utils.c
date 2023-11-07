/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:35:10 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/07 15:43:14 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_stack **stack)
{
	unsigned int	negative;
	unsigned int	i;
	long			atoi;

	negative = 0;
	atoi = 0;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
		negative = (str[i++] == '-');
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		atoi = (atoi * 10) + (str[i] - 48);
		if (atoi > INT_MAX || atoi < INT_MIN)
		{
			stack_clear(stack);
			error_exit();
		}
		i++;
	}
	if (negative)
		return (atoi * -1);
	return (atoi);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 7 && c <= 13));
}
