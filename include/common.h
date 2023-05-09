/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:28:49 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/08 07:56:30 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../libft/libft.h"

// struct for stacks
typedef struct s_stack
{
	int				value;
	int				steps_a;
	int				steps_b;
	int				total;
	struct s_stack	*next;
}	t_stack;

// stack functions
t_stack	*copy(t_stack *stack);
void	add_new(t_stack **stack, int value);
int		compare(t_stack *lst1, t_stack *lst2);
t_stack	*get(t_stack *stack, int pos);
int		stack_size(t_stack *stack);
void	stack_print(t_stack *lst);
int		max(t_stack *stack);
int		min(t_stack *stack);
int		get_pos(t_stack *stack, int value);

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

// src
int		ft_issorted(t_stack *stack_a, t_stack *stack_b);
t_stack	*validator(int argc, char **argv);
void	free_stacks(t_stack **stack);

#endif