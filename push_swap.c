/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/01/01 20:02:17 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	amount;
	int	a_size;

	amount = argc - 1;
	a_size = amount;
	stack_a = random_stack(amount);
	stack_b = ft_calloc(amount, sizeof(int));
	print_stacks(stack_a, a_size, stack_b, amount - a_size);
	ft_swap(stack_a, a_size);
	pb(stack_b, amount - a_size, stack_a, &a_size);
	print_stacks(stack_a, a_size, stack_b, amount - a_size);
	return (0);
}
