/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:29:01 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/20 16:20:57 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*new_move(t_stack **stack_a, t_stack **stack_b, int i)
{
	char	*move;

	if (i == 0)
		move = sa(stack_a, stack_b);
	else if (i == 1)
		move = sb(stack_a, stack_b);
	else if (i == 2)
		move = ss(stack_a, stack_b);
	else if (i == 3)
		move = pa(stack_a, stack_b);
	else if (i == 4)
		move = pb(stack_a, stack_b);
	else if (i == 5)
		move = ra(stack_a, stack_b);
	else if (i == 6)
		move = rb(stack_a, stack_b);
	else if (i == 7)
		move = rr(stack_a, stack_b);
	else if (i == 8)
		move = rra(stack_a, stack_b);
	else if (i == 9)
		move = rrb(stack_a, stack_b);
	else
		move = rrr(stack_a, stack_b);
	return (move);
}

char	*short_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_entry	*dictionary;
	int		i;
	int		j;
	char	*move;

	j = 0;
	dictionary = dict_new(stack_a, stack_b, "");
	while (1)
	{
		i = 0;
		while (i < 11)
		{
			stack_a = copy(dict_get(dictionary, j)->stack_a);
			stack_b = copy(dict_get(dictionary, j)->stack_b);
			move = new_move(&stack_a, &stack_b, i++);
			if (ft_strlen(move)
				&& !ft_is_in_list(dictionary, stack_a, stack_b))
				dict_add_back(&dictionary, dict_new(stack_a, stack_b, \
				ft_strjoin(dict_get(dictionary, j)->moves, move)));
			if (ft_issorted(stack_a, stack_b))
				return (dict_get(dictionary, dict_size(dictionary) - 1)->moves);
		}
		j++;
	}
	return ("");
}
