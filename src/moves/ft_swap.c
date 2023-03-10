/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:07 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/10 15:15:37 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*sa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	(void)stack_b;
	if (stack_size(*stack_a) <= 1)
		return ("");
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = (*stack_a)->next;
	(*stack_a)->next = aux;
	return ("sa\n");
}

char	*sb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	(void)stack_a;
	if (stack_size(*stack_b) <= 1)
		return ("");
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = (*stack_b)->next;
	(*stack_b)->next = aux;
	return ("sb\n");
}

char	*ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_a, stack_b);
	return ("ss\n");
}
