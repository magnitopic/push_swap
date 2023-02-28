/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:43:42 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/28 17:14:30 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*ra(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	(void)stack_b;
	if (ft_lstsize(*stack_a) <= 1)
		return ("");
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_get(*stack_a, ft_lstsize(*stack_a) - 1)->next = aux;
	return ("ra\n");
}

char	*rb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	(void)stack_a;
	if (ft_lstsize(*stack_b) <= 1)
		return ("");
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ft_get(*stack_b, ft_lstsize(*stack_b) - 1)->next = aux;
	return ("rb\n");
}

char	*rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, stack_b);
	rb(stack_a, stack_b);
	return ("rr\n");
}
