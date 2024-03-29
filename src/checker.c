/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:49:32 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/25 21:40:21 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*list;

	stack_a = NULL;
	stack_b = NULL;
	list = NULL;
	if (argc < 2)
		return (0);
	argv[1] = argjoin(argc, argv);
	argc = count_words(argv[1]);
	argv = split(argv[1]);
	fill_stack_a(&stack_a, argc, argv);
	dup_check(&stack_a, argc, argv);
	read_cmd(&list, argc, argv, &stack_a);
	perform_cmd(&list, &stack_a, &stack_b);
	if (ordered(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_loop(argv, argc);
	clear_list(&list);
	clear_stacks(&stack_a, &stack_b);
}

void	read_cmd(t_list **list, int argc, char *argv[], t_stack **stack_a)
{
	char	*save;

	while (1)
	{
		save = get_next_line(0);
		if (save == NULL)
			break ;
		if (add_cmd_end(list, save) == 1)
		{
			stack_clear(stack_a);
			clear_list(list);
			clear_loop(argv, argc);
			error_exit_free_str(save);
		}
	}
}

int	add_cmd_end(t_list **list, char *s)
{
	t_list	*new;
	t_list	*tmp;

	if (!valid_cmd(s))
		return (1);
	new = (t_list *)malloc(sizeof(t_list));
	s[ft_strlen(s) - 1] = '\0';
	new -> cmd = s;
	new -> next = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		tmp -> next = new;
	}
	return (0);
}

int	valid_cmd(char *s)
{
	return (ft_strcmp(s, "sa\n") == 0 || ft_strcmp(s, "sb\n") == 0
		|| ft_strcmp(s, "ss\n") == 0 || ft_strcmp(s, "pa\n") == 0
		|| ft_strcmp(s, "pb\n") == 0 || ft_strcmp(s, "ra\n") == 0
		|| ft_strcmp(s, "rb\n") == 0 || ft_strcmp(s, "rr\n") == 0
		|| ft_strcmp(s, "rra\n") == 0 || ft_strcmp(s, "rrb\n") == 0
		|| ft_strcmp(s, "rrr\n") == 0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
