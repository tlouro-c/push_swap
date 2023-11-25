/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:26:57 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/25 16:38:57 by tlouro-c         ###   ########.fr       */
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

typedef struct s_mid
{
	int			count_below;
	enum e_path	path;
}	t_mid;

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

typedef struct s_list
{
	char			*cmd;
	struct s_list	*next;
}	t_list;

//* START of stack_essentials.c */

void	push(t_stack **stack, long number);
long	pop(t_stack **stack);
void	insert_end(t_stack **stack, long number);
long	pop_end(t_stack **stack);
void	stack_clear(t_stack **stack);

/* END of stack_essentials.c */

//* START of errors_utils.c */

void	error_exit(void);
int		valid_nr_check(char *s);
void	dup_check(t_stack **stack, int argc, char *argv[]);
void	error_exit_free_str(char *s);
void	error_exit_free_stack(t_stack **stack, int argc, char *argv[]);
/* END of errors_utils.c */

//* START of extra_utils.c */

int		ft_atoi(const char *str, t_stack **stack, int argc, char *argv[]);
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
char	*argjoin(int argc, char *argv[]);
char	**clear_loop(char **array, int len);

//? COMMANDS HERE

//* START of swaps.c */
void	swap(t_stack **stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack1, t_stack **stack2);
void	checker_ss(t_stack **stack1, t_stack **stack2);
//* START of pushes.c */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	checker_pa(t_stack **stack_a, t_stack **stack_b);
void	checker_pb(t_stack **stack_a, t_stack **stack_b);
//* START of rotate.c */
void	rotate(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack1, t_stack **stack2);
void	checker_rr(t_stack **stack1, t_stack **stack2);
//* START of reverse_rotate.c */
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack1, t_stack **stack2);
void	checker_rrr(t_stack **stack1, t_stack **stack2);

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

void	last_rotates(t_stack **stack_a, t_min *min, int cost);

int		find_min(t_stack *stack);
int		ordered(t_stack *stack_a);

//* End of Algorithm Part

void	read_cmd(t_list **list);
void	add_cmd_end(t_list **list, char *string);
int		valid_cmd(char *s);
int		ft_strcmp(char *s1, char *s2);
void	print_list(t_list *list);
void	perform_cmd(t_list **list, t_stack **stack_a, t_stack **stack_b);
void	exec_cmd(char *cmd, t_stack **stack_a, t_stack **stack_b);
void	clear_list(t_list **list);
void	clear_stacks(t_stack **stack_a, t_stack **stack_b);

void	bubble_sort(int *array, int size);
int		mid(t_stack *stack);
t_mid	below_mid(t_stack *stack, int mid, int size);
void	a_to_b(t_stack **stack_a, t_stack **stack_b);

#endif /* PUSH_SWAP_H */
