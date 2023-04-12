/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:29:01 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/12 17:04:01 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*new_move(t_stack **stack_a, t_stack **stack_b, int i)
{
	char	*(*moves[11])(t_stack **stack_a, t_stack **stack_b);

	moves[0] = &sa;
	moves[1] = &sb;
	moves[2] = &ss;
	moves[3] = &pa;
	moves[4] = &pb;
	moves[5] = &ra;
	moves[6] = &rb;
	moves[7] = &rr;
	moves[8] = &rra;
	moves[9] = &rrb;
	moves[10] = &rrr;
	return (moves[i](stack_a, stack_b));
}

static void	new_level(t_stack *stack_a, t_stack *stack_b, t_entry *dict, int j)
{
	int		i;
	char	*move;

	i = 0;
	while (i < 11)
	{
		stack_a = copy(dict_get(dict, j)->stack_a);
		stack_b = copy(dict_get(dict, j)->stack_b);
		move = new_move(&stack_a, &stack_b, i);
		if (ft_strlen(move) && !ft_inlist(dict, stack_a, stack_b))
		{
			dict_add_back(&dict, dict_new(stack_a, stack_b, \
			ft_strjoin(dict_get(dict, j)->moves, move)));
			if (ft_issorted(stack_a, stack_b))
			{
				ft_printf("%s", dict_get(dict, dict_size(dict) - 1)->moves);
				free_dict(dict);
				exit (0);
			}
		}
		else
			(free_stacks(&stack_a), free_stacks(&stack_b));
		i++;
	}
}

void	short_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_entry	*dictionary;
	int		j;

	j = 0;
	dictionary = dict_new(stack_a, stack_b, ft_calloc(1, 1));
	while (1)
	{
		new_level(stack_a, stack_b, dictionary, j);
		j++;
	}
}
