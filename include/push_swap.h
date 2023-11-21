/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:26:57 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/21 11:25:41 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

enum e_path {
	ROTATE,
	REVERSE_ROTATE
};

typedef struct s_min
{
	int			value;
	int			cost;
	enum e_path	path;
}	t_min;

typedef struct s_stack
{
	enum e_path		path;
	enum e_path		path_target;
	int				cost;
	int				cost_target;
	int				total_cost;
	int				target;
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
int		space(int c);
size_t	ft_strlen(char *s);
int		abs(int c);

/* END of errors_utils.c */

//* START of fill_stack_a.c */

void	fill_stack_a(t_stack **stack, int argc, char *argv[]);

/* END of fill_stack_a.c */

//* START of testing_essentials.c */

void	print_stack(t_stack *stack);

/* END of testing_essentials.c */

int		count_words(char *s);
char	**split(char *string);

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
void	rb(t_stack **stack);
void	rr(t_stack **stack1, t_stack **stack2);
//* START of reverse_rotate.c */
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack1, t_stack **stack2);

//? END OF COMMANDS

//* Algorithm Part

int		first(t_stack *stack);
int		second(t_stack *stack);
int		third(t_stack *stack);
void	mini_sort(t_stack **stack);

int		list_len_till(t_stack **stack, int max);
void	algorithm_base(t_stack **stack_a, t_stack **stack_b);
void	algorithm(t_stack **stack_a, t_stack **stack_b);
void	get_targets(t_stack *stack_a, t_stack *stack_b);

void	get_data_cost(t_stack *stack_b);
void	get_target_cost(t_stack *stack_a, t_stack *stack_b);
t_stack	get_costs(t_stack *stack_a, t_stack *stack_b);

void	rotate_same_path(t_stack **stack_a, t_stack **stack_b, t_stack cheap);
void	move_cheapest(t_stack **stack_a, t_stack **stack_b, t_stack cheapest);

void	last_rotates(t_stack **stack_a, t_min min);

int		find_min(t_stack *stack);
int		ordered(t_stack *stack_a);

//* End of Algorithm Part

#endif /* PUSH_SWAP_H */
