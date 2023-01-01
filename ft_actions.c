/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:07 by alaparic          #+#    #+#             */
/*   Updated: 2023/01/01 12:15:23 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack_a, int a_size)
{
	int	aux;

	if (a_size <= 1)
		return ;
	aux = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = aux;
}

void	sb(int *stack_b, int b_size)
{
	int	aux;

	if (b_size <= 1)
		return ;
	aux = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = aux;
}

void	ss(int *stack_a, int a_size, int *stack_b, int b_size)
{
	sa(stack_a, a_size);
	sa(stack_b, b_size);
}

void	pa(int *stack_a, int *a_size, int *stack_b, int b_size)
{
	int	*new_stack_a;
	int	*new_stack_b;
	int	i;

	if (b_size < 1)
		return ;
	*a_size = *a_size + 1;
	i = *a_size;
	while (i >= 0)
	{
		stack_a[i + 1] = stack_a[i];
		i--;
	}
	stack_a[0] = stack_b[0];
	while (i < b_size)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
}

int	main(void)
{
	int	*stack_a;
	int	*stack_b;
	int	a_size;
	int	total_size;
	int	i;

	a_size = 3;
	total_size = 5;
	stack_a = ft_calloc(5, sizeof(int));
	stack_b = ft_calloc(5, sizeof(int));
	stack_a[0] = 1;
	stack_a[1] = 2;
	stack_a[2] = 3;
	stack_b[0] = 4;
	stack_b[1] = 5;
	i = 0;
	while (i < a_size)
		ft_printf("%d", stack_a[i++]);
	ft_printf("\n");
	i = 0;
	while (i < total_size - a_size)
		ft_printf("%d", stack_b[i++]);
	ft_printf("\n");
	ft_printf("\n");
	pa(stack_a, &a_size, stack_b, (total_size - a_size));
	i = 0;
	while (i < a_size)
		ft_printf("%d", stack_a[i++]);
	ft_printf("\n");
	i = 0;
	while (i < total_size - a_size)
		ft_printf("%d", stack_b[i++]);
	ft_printf("\n");
	return (0);
}
