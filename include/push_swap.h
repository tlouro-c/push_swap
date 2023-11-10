/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:26:57 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/10 00:33:18 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

//* START of stack_essentials.c */

void	push(t_stack **stack, int number);
int		pop(t_stack **stack);
void	insert_end(t_stack **stack, int number);
int		pop_end(t_stack **stack);
void	stack_clear(t_stack **stack);

/* END of stack_essentials.c */

//* START of errors_utils.c */

void	error_exit(void);
void	stack_empty(void);
void	valid_nr_check(char *s);
void	dup_check(t_stack **stack);

/* END of errors_utils.c */

//* START of extra_utils.c */

int		ft_atoi(const char *str, t_stack **stack);
int		ft_isdigit(int c);
int		ft_isspace(int c);

/* END of errors_utils.c */

//* START of fill_stack_a.c */

void	fill_stack_a(t_stack **stack, int argc, char *argv[]);

/* END of fill_stack_a.c */

//* START of testing_essentials.c */

void	print_stack(t_stack *stack);

/* END of etesting_essentials.c */

//? COMMANDS HERE

//* START of swaps.c */
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack1, t_stack **stack2);
//* START of pushes.c */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
//* START of rotate.c */
void	rotate(t_stack **stack);
void	ra(t_stack **stack);
void	ra(t_stack **stack);
void	rr(t_stack **stack1, t_stack **stack2);
//* START of reverse_rotate.c */
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack);
void	rra(t_stack **stack);
void	rrr(t_stack **stack1, t_stack **stack2);

//? END OF COMMANDS

#endif /* PUSH_SWAP_H */
