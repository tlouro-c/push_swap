/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:21:56 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/10 13:50:32 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int count_words(char *s)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && !space(s[i])) || (!space(s[i]) && space(s[i - 1])))
			counter++;
		i++;
	}
	return (counter);
}

char	*strdupmod(char *s)
{
	char *new;
	int	i;

	new = (char *)malloc(ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && !space(s[i]))
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**clear_loop(char **array, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(array[i++]);
	free(array);
	return (NULL);
}

char	**split(char *s)
{
	char 	**splited;
	int		i;
	int		j;

	splited = (char **)malloc((count_words(s) + 1 + 1) * sizeof(char **));
	if (splited == NULL)
		return (NULL);
	i = 0;
	j = 0;
	splited[j++] = strdupmod("./push_swap");
	while (s[i] != '\0')
	{
		if ((i == 0 && !space(s[i])) || (!space(s[i]) && space(s[i - 1])))
		{
			splited[j] = strdupmod(&s[i]);
			if (splited[j] == NULL)
				return (clear_loop(splited, j));
			i += ft_strlen(splited[j]);
			j++;
		}
		else
			i++;
	}
	splited[j] = NULL;
	return (splited);
}
