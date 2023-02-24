/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:12:13 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/24 17:41:48 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (ft_lstsize(*stack_a) == 0)
		return ("");
	aux = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = aux;
	return ("pa");
}

char	*pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (ft_lstsize(*stack_b) == 0)
		return ("");
	aux = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = aux;
	return ("pb");
}
