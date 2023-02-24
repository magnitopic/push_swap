/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:07 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/24 16:07:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*sa(t_list *stack_a, t_list *stack_b)
{
	t_list	*aux;

	//aux = stack_a[ft_lstsize(stack_a) - 1];
	aux = stack_a;
	stack_a = stack_a->next;
	aux->next = stack_a->next;
	stack_a->next = aux;
	return (stack_a);
}

char	*sb(t_list *stack_a, t_list *stack_b)
{
	t_list	aux;

	aux = stack_b[ft_lstsize(stack_b)-1];
	return ("sb");
}