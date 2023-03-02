/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:29:01 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/02 17:19:26 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*busca(t_list *stack_a, t_list *stack_b)
{
	t_entry	*dictionary;
	int		i;
	int		j;
	t_list	*stack_a_cpy;
	t_list	*stack_b_cpy;
	char	*move;
	//char	*(*moves[11])(t_list stack_a, t_list stack_b);

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
			if (ft_issorted(stack_a_cpy, stack_b_cpy))
				return (dict_get(dictionary, i + j)->moves);
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
			i++;
			if (ft_is_in_function(dictionary, stack_a_cpy, stack_b_cpy))
				dict_add_back(&dictionary, dict_new(stack_a_cpy, stack_b_cpy, ft_strjoin(dict_get(dictionary, j)->moves, move)));
		}
		ft_printf("===================");
		i = 0;
		while (i < dict_size(dictionary))
		{
			ft_lstprint_int(dict_get(dictionary, i)->stack_a);
			ft_lstprint_int(dict_get(dictionary, i)->stack_b);
			i++;
		}
		j++;
	}
	return ("");
}
