/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:29:01 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/27 16:06:47 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*busca(t_list *stack_a, t_list *stack_b)
{
	//t_entry	*dictionary;
	//char	*(*moves[11])(t_list stack_a, t_list stack_b);
	int		i;
	t_list	*stack_a_cpy;
	t_list	*stack_b_cpy;

	i = 0;
	/* while (!ft_issorted(stack_a, stack_b))
	{ */
	while (i < 11)
	{
		stack_a_cpy = ft_lstcpy(stack_a);
		stack_b_cpy = ft_lstcpy(stack_b);
		(void)stack_b;
		if (i == 0)
			sa(&stack_a_cpy, &stack_b_cpy);
		else if (i == 1)
			sb(&stack_a_cpy, &stack_b_cpy);
		else if (i == 2)
			ss(&stack_a_cpy, &stack_b_cpy);
		else if (i == 3)
			pa(&stack_a_cpy, &stack_b_cpy);
		else if (i == 4)
			pb(&stack_a_cpy, &stack_b_cpy);
		else if (i == 5)
			ra(&stack_a_cpy, &stack_b_cpy);
		else if (i == 6)
			rb(&stack_a_cpy, &stack_b_cpy);
		else if (i == 7)
			rr(&stack_a_cpy, &stack_b_cpy);
		else if (i == 8)
			rra(&stack_a_cpy, &stack_b_cpy);
		else if (i == 9)
			rrb(&stack_a_cpy, &stack_b_cpy);
		else if (i == 10)
			rrr(&stack_a_cpy, &stack_b_cpy);
		i++;
		ft_printf("Stack_a_cpy:");
		ft_lstprint_int(stack_a_cpy);
		ft_printf("Stack_b:");
		ft_lstprint_int(stack_b_cpy);
		ft_printf("\n================================\n");
	}
	//}
	return ("ye");
}
