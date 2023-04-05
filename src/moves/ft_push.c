/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:12:13 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/05 16:35:19 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (stack_size(*stack_b) == 0)
		return ("");
	aux = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = aux;
	return ("pa\n");
}

char	*pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (stack_size(*stack_a) == 0)
		return ("");
	aux = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = aux;
	return ("pb\n");
}
