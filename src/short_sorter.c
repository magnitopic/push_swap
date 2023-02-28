/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:29:01 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/28 16:37:08 by alaparic         ###   ########.fr       */
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
	while (j < dict_size(dictionary))
	{
		i = 0;
		while (i < 11)
		{
			move = dict_get(dictionary, j)->moves;
			stack_a_cpy = ft_lstcpy(dict_get(dictionary, j)->stack_a);
			stack_b_cpy = ft_lstcpy(dict_get(dictionary, j)->stack_b);
			if (i == 0)
				move = ft_strjoin(move, sa(&stack_a_cpy, &stack_b_cpy));
			else if (i == 1)
				move = ft_strjoin(move, sb(&stack_a_cpy, &stack_b_cpy));
			else if (i == 2)
				move = ft_strjoin(move, ss(&stack_a_cpy, &stack_b_cpy));
			else if (i == 3)
				move = ft_strjoin(move, pa(&stack_a_cpy, &stack_b_cpy));
			else if (i == 4)
				move = ft_strjoin(move, pb(&stack_a_cpy, &stack_b_cpy));
			else if (i == 5)
				move = ft_strjoin(move, ra(&stack_a_cpy, &stack_b_cpy));
			else if (i == 6)
				move = ft_strjoin(move, rb(&stack_a_cpy, &stack_b_cpy));
			else if (i == 7)
				move = ft_strjoin(move, rr(&stack_a_cpy, &stack_b_cpy));
			else if (i == 8)
				move = ft_strjoin(move, rra(&stack_a_cpy, &stack_b_cpy));
			else if (i == 9)
				move = ft_strjoin(move, rrb(&stack_a_cpy, &stack_b_cpy));
			else if (i == 10)
				move = ft_strjoin(move, rrr(&stack_a_cpy, &stack_b_cpy));
			i++;
			ft_printf("Helper: %d\n", dict_size(dictionary));
			if (ft_strlen(move))
				dict_add_back(&dictionary, dict_new(stack_a_cpy, stack_b_cpy, move));
			if (ft_issorted(stack_a_cpy, stack_b_cpy)){
				return (move);
			}
		}
		j++;
	}
	return ("ye");
}
