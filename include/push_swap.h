/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:21:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/02 16:11:40 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// struct for dictionary
typedef struct s_entry
{
	t_list			*stack_a;
	t_list			*stack_b;
	char			*moves;
	struct s_entry	*next;
}	t_entry;

// dictionary functions
t_entry	*dict_new(t_list *stack_a, t_list *stack_b, char *moves);
int		dict_size(t_entry *dictionary);
void	dict_add_back(t_entry **lst, t_entry *new);
t_entry	*dict_get(t_entry *dict, int pos);
int	ft_is_in_function(t_entry *dict, t_list *stack_a, t_list *stack_b);

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