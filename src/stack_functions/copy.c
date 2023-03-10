/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:59:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/10 16:58:39 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*copy(t_stack *stack)
{
	int		i;
	t_stack	*new_stack;
	int		*aux;

	if (!stack_size(stack))
		return (NULL);
	new_stack = NULL;
	i = 0;
	aux = malloc(sizeof(int));
	*aux = get(stack, i++)->value;
	new_stack = add_new(new_stack, *aux);
	while (i < stack_size(stack))
	{
		aux = malloc(sizeof(int));
		*aux = get(stack, i++)->value;
		add_new(new_stack, *aux);
	}
	return (new_stack);
}
