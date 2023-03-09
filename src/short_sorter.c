/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:29:01 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/09 16:23:53 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*busca(t_stack *stack_a, t_stack *stack_b)
{
	t_entry	*dictionary;
	int		i;
	int		j;
	t_stack	*stack_a_cpy;
	t_stack	*stack_b_cpy;
	char	*move;

	j = 0;
	dictionary = dict_new(stack_a, stack_b, "");
	while (1)
	{
		i = 0;
		while (i < 11)
		{
			move = "";
			stack_a_cpy = ft_lstcpy(dict_get(dictionary, j)->stack_a);
			stack_b_cpy = ft_lstcpy(dict_get(dictionary, j)->stack_b);
			if (i == 0)
				move = sa(&stack_a_cpy, &stack_b_cpy);
			else if (i == 1)
				move = sb(&stack_a_cpy, &stack_b_cpy);
			else if (i == 2)
				move = ss(&stack_a_cpy, &stack_b_cpy);
			else if (i == 3)
				move = pa(&stack_a_cpy, &stack_b_cpy);
			else if (i == 4)
				move = pb(&stack_a_cpy, &stack_b_cpy);
			else if (i == 5)
				move = ra(&stack_a_cpy, &stack_b_cpy);
			else if (i == 6)
				move = rb(&stack_a_cpy, &stack_b_cpy);
			else if (i == 7)
				move = rr(&stack_a_cpy, &stack_b_cpy);
			else if (i == 8)
				move = rra(&stack_a_cpy, &stack_b_cpy);
			else if (i == 9)
				move = rrb(&stack_a_cpy, &stack_b_cpy);
			else if (i == 10)
				move = rrr(&stack_a_cpy, &stack_b_cpy);
			if (ft_strlen(move)
				&& !ft_is_in_list(dictionary, stack_a_cpy, stack_b_cpy))
				dict_add_back(&dictionary, dict_new(stack_a_cpy, stack_b_cpy, ft_strjoin(dict_get(dictionary, j)->moves, move)));
			if (ft_issorted(stack_a_cpy, stack_b_cpy))
				return (dict_get(dictionary, dict_size(dictionary) - 1)->moves);
			i++;
		}
		j++;
	}
	return ("");
}
