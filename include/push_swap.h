/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:21:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/13 15:36:07 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// struct for stacks
typedef struct s_stack
{
	int				value;
	int				pasos_a;
	int				pasos_b;
	struct s_stack	*next;
}	t_stack;

// struct for dictionary
typedef struct s_entry
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*moves;
	struct s_entry	*next;
}	t_entry;

// stack functions
t_stack	*copy(t_stack *stack);
t_stack	*add_new(t_stack *stack, int value);
int		compare(t_stack *lst1, t_stack *lst2);
t_stack	*get(t_stack *stack, int pos);
int		stack_size(t_stack *stack);

// dictionary functions
int		dict_size(t_entry *dictionary);
t_entry	*dict_get(t_entry *dict, int pos);
void	dict_add_back(t_entry **lst, t_entry *new);
t_entry	*dict_new(t_stack *stack_a, t_stack *stack_b, char *moves);

// Moves
char	*sa(t_stack **stack_a, t_stack **stack_b);
char	*sb(t_stack **stack_a, t_stack **stack_b);
char	*ss(t_stack **stack_a, t_stack **stack_b);
char	*pa(t_stack **stack_a, t_stack **stack_b);
char	*pb(t_stack **stack_a, t_stack **stack_b);
char	*ra(t_stack **stack_a, t_stack **stack_b);
char	*rb(t_stack **stack_a, t_stack **stack_b);
char	*rr(t_stack **stack_a, t_stack **stack_b);
char	*rra(t_stack **stack_a, t_stack **stack_b);
char	*rrb(t_stack **stack_a, t_stack **stack_b);
char	*rrr(t_stack **stack_a, t_stack **stack_b);

// SRC
char	*short_sort(t_stack *stack_a, t_stack *stack_b);
int		ft_is_in_list(t_entry *dict, t_stack *stack_a, t_stack *stack_b);
int		ft_issorted(t_stack *stack_a, t_stack *stack_b);
t_stack	*validator(int argc, char **argv);
void	stack_print(t_stack *lst);
char	*modern_times(t_stack *stack_a, t_stack *stack_b);

/* char	*new_values(t_entry *dictionary, int j);
int		*count_min_steps(t_stack *stack_a, t_stack *stack_b);
int		count_steps_a(t_stack *stack_a); */

#endif