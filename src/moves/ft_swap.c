/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:07 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/25 15:23:32 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*sa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	(void)stack_b;
	if (ft_lstsize(*stack_a) <= 1)
		return ("");
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = (*stack_a)->next;
	(*stack_a)->next = aux;
	return ("sa\n");
}

char	*sb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	(void)stack_a;
	if (ft_lstsize(*stack_b) <= 1)
		return ("");
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = (*stack_b)->next;
	(*stack_b)->next = aux;
	return ("sb\n");
}

char	*ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_a, stack_b);
	return ("ss\n");
}
