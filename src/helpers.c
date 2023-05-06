/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:24:27 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/03 15:04:25 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Function to check wether the stacks are sorted.
 * For that to be true stack_b must be empty and
 * stack_a must have all values from smallest to largest.
 */
int	ft_issorted(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	len;

	if (stack_size(stack_b) != 0)
		return (0);
	i = 0;
	len = stack_size(stack_a);
	while ((len - 1) > i)
	{
		if (get(stack_a, i)->value
			> get(stack_a, i + 1)->value)
			return (0);
		i++;
	}
	return (1);
}

/**
 * Recibes the dictionary and the two stacks.
 * Checks thru all entries in the dictionary comparing
 * them to stack_a and stack_b.
 * If the stack values are already in the dictionary 1 is returned, otherwise 0.
 */
int	ft_inlist(t_entry *dict, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < dict_size(dict))
	{
		if (compare(dict_get(dict, i)->stack_a, stack_a)
			&& compare(dict_get(dict, i)->stack_b, stack_b))
			return (1);
		i++;
	}
	return (0);
}

/**
 * Prints the moves that need to be done to sort any 3 numbers.
*/
void	sort_three(t_stack **a, t_stack **b)
{
	int	one;
	int	two;
	int	three;

	one = (*a)->value;
	two = (*a)->next->value;
	three = (*a)->next->next->value;
	if (one < two && two > three && one < three)
	{
		write(1, ra(a, b), 3);
		write(1, sa(a, b), 3);
		write(1, rra(a, b), 4);
	}
	else if (one > two && two > three && one > three)
	{
		write(1, sa(a, b), 3);
		write(1, rra(a, b), 4);
	}
	else if (one > two && two < three && one < three)
		write(1, sa(a, b), 3);
	else if (one < two && two > three && one > three)
		write(1, rra(a, b), 4);
	else if (one > two && two < three && one > three)
		write(1, ra(a, b), 3);
}

/**
 * Recursive function to free a stack.
*/
void	free_stacks(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	if ((*stack)->next != NULL)
		free_stacks(&(*stack)->next);
	(free(*stack), *stack = NULL);
}

/**
 * Recursive function to free a dictionary and it's contents.
*/
void	free_dict(t_entry *dict)
{
	if (dict == NULL)
		return ;
	if (dict->next != NULL)
		free_dict(dict->next);
	free_stacks(&dict->stack_a);
	free_stacks(&dict->stack_b);
	free(dict->moves);
	(free(dict), dict = NULL);
}
