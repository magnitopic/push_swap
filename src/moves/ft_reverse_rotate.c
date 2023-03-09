/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:48:50 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/09 16:18:05 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*rra(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	(void)stack_b;
	if (ft_lstsize(*stack_a) <= 1)
		return ("");
	aux = ft_get(*stack_a, ft_lstsize(*stack_a) - 1);
	ft_get(*stack_a, ft_lstsize(*stack_a) - 2)->next = NULL;
	aux->next = *stack_a;
	*stack_a = aux;
	return ("rra\n");
}

char	*rrb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	(void)stack_a;
	if (ft_lstsize(*stack_b) <= 1)
		return ("");
	aux = ft_get(*stack_b, ft_lstsize(*stack_b) - 1);
	ft_get(*stack_b, ft_lstsize(*stack_b) - 2)->next = NULL;
	aux->next = *stack_b;
	*stack_b = aux;
	return ("rrb\n");
}

char	*rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, stack_b);
	rrb(stack_a, stack_b);
	return ("rrr\n");
}
