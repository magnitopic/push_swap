/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:21:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/04 13:26:39 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

// struct for dictionary
typedef struct s_entry
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*moves;
	struct s_entry	*next;
}	t_entry;

// dictionary functions
int		dict_size(t_entry *dictionary);
t_entry	*dict_get(t_entry *dict, int pos);
void	dict_add_back(t_entry **lst, t_entry *new);
t_entry	*dict_new(t_stack *stack_a, t_stack *stack_b, char *moves);

// SRC
t_entry	*short_sort(t_stack *stack_a, t_stack *stack_b);
char	*modern_times(t_stack **stack_a, t_stack **stack_b);
int		ft_inlist(t_entry *dict, t_stack *stack_a, t_stack *stack_b);
void	count_steps_a(t_stack *stack_a);
void	count_steps_b(t_stack *stack_a, t_stack *stack_b);
void	totaliza(t_stack *stack_a);
int		min_steps(t_stack **stack_a);
char	*sort_three(t_stack **a, t_stack **b, char *moves);
void	free_dict(t_entry *dict);

#endif