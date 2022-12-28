/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/28 18:29:22 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(int *stack_a, int *stack_b, int longitud)
{
	int	i;

	while (i < longitud)
	{

	}
}

void	sa(int *stack_a, int a_size)
{
	int	aux;

	if (a_size <= 1)
		return ;
	aux = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = aux;
}

int	main(void)
{
	int	*stack_a;
	int	*stack_b;
	int	amount;
	int	a_size;
	int	i;

	amount = 5;
	a_size = amount;
	stack_a = random_stack(amount);
	stack_b = ft_calloc(amount, sizeof(int));
	while (i < amount)
	{
		ft_printf("%d, ", stack_a[i++]);
	}
	ft_printf("\t");
	i = 0;
	while (i < amount)
	{
		ft_printf("%d, ", stack_b[i++]);
	}
	ft_printf("\n");
	sa(stack_a);
	i = 0;
	while (i < amount)
	{
		ft_printf("%d, ", stack_a[i++]);
	}
	ft_printf("\t");
	i = 0;
	while (i < amount)
	{
		ft_printf("%d, ", stack_b[i++]);
	}
	return (0);
}
