/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:07 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/24 17:08:04 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*sa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	(void)stack_b;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = (*stack_a)->next;
	(*stack_a)->next = aux;
	return ("sa");
}

char	*sb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	(void)stack_a;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = (*stack_b)->next;
	(*stack_b)->next = aux;
	return ("sb");
}
