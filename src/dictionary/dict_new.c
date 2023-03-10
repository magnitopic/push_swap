/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:08:36 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/10 17:00:51 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_entry	*dict_new(t_stack *stack_a, t_stack *stack_b, char *moves)
{
	t_entry	*new;

	new = malloc(sizeof(t_entry));
	if (!new)
		return (NULL);
	new->stack_a = stack_a;
	new->stack_b = stack_b;
	new->moves = moves;
	return (new);
}
