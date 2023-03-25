/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:28:49 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/24 16:30:11 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../libft/libft.h"

// struct for stacks
typedef struct s_stack
{
	int				value;
	int				pasos_a;
	int				pasos_b;
	struct s_stack	*next;
}	t_stack;

// stack functions
t_stack	*copy(t_stack *stack);
t_stack	*add_new(t_stack *stack, int value);
int		compare(t_stack *lst1, t_stack *lst2);
t_stack	*get(t_stack *stack, int pos);
int		stack_size(t_stack *stack);

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

#endif