/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:09:41 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/31 16:11:42 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Functions for t_entry struct.
 * -	Get size by counting elements
 * -	Get one entry form the list
 * -	Add element to the back of the dictionary
 * -	Create the dictionary size
 */

int	dict_size(t_entry *dictionary)
{
	int	len;

	len = 1;
	if (dictionary != NULL)
	{
		while (dictionary->next != NULL)
		{
			dictionary = dictionary->next;
			len++;
		}
		return (len);
	}
	return (0);
}

t_entry	*dict_get(t_entry *dict, int pos)
{
	int		i;
	t_entry	*node;

	node = dict;
	i = 0;
	while (i < pos)
	{
		i++;
		node = node->next;
	}
	return (node);
}

void	dict_add_back(t_entry **lst, t_entry *new)
{
	if (*lst == 0)
		*lst = new;
	else
	{
		while ((*lst)->next != 0)
				lst = &(*lst)->next;
			(*lst)->next = new;
	}
}

t_entry	*dict_new(t_stack *stack_a, t_stack *stack_b, char *moves)
{
	t_entry	*new;

	new = malloc(sizeof(t_entry));
	if (!new)
		return (NULL);
	new->stack_a = stack_a;
	new->stack_b = stack_b;
	new->moves = moves;
	new->next = NULL;
	return (new);
}
