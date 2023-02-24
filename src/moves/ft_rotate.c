/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:43:42 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/24 19:18:47 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*ra(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	(void)stack_b;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_get(*stack_a, ft_lstsize(*stack_a) - 1)->next = aux;

	return ("ra");
}
