/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:21:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/27 15:14:26 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// struct for dictionary
typedef struct s_entry
{
	char			*stack_a;
	char			*stack_b;
	struct s_entry	*next;
}	t_entry;

// dictionary functions

// Moves functions
char	*sa(t_list **stack_a, t_list **stack_b);
char	*sb(t_list **stack_a, t_list **stack_b);
char	*ss(t_list **stack_a, t_list **stack_b);
char	*pa(t_list **stack_a, t_list **stack_b);
char	*pb(t_list **stack_a, t_list **stack_b);
char	*ra(t_list **stack_a, t_list **stack_b);
char	*rb(t_list **stack_a, t_list **stack_b);
char	*rr(t_list **stack_a, t_list **stack_b);
char	*rra(t_list **stack_a, t_list **stack_b);
char	*rrb(t_list **stack_a, t_list **stack_b);
char	*rrr(t_list **stack_a, t_list **stack_b);

// SRC
int		ft_issorted(t_list *stack_a, t_list *stack_b);
char	*busca(t_list *stack_a, t_list *stack_b);

#endif