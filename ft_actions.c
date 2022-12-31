/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:07 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/31 13:55:18 by alaparic         ###   ########.fr       */
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

void	pa(int *stack_a, int *a_size, int *stack_b, int *b_size)
{
	int	*new_stack_a;
	int	*new_stack_b;
	int	i;

	if (*b_size < 1)
		return ;
	new_stack_a = ft_calloc(*a_size + *b_size, sizeof(int));
	new_stack_b = ft_calloc(*a_size + *b_size, sizeof(int));
	new_stack_a[0] = stack_b[0];
	*a_size = *a_size + 1;
	*b_size = *b_size - 1;
	i = 1;
	while (i < *a_size)
	{
		new_stack_a[i] = stack_a[i - 1];
		i++;
	}
	i = 0;
	while (i < *b_size)
	{
		new_stack_b[i] = stack_b[i + 1];
		i++;
	}
	ft_memcpy(stack_a, new_stack_a, *a_size * sizeof(int));
	ft_memcpy(stack_b, new_stack_b, *b_size * sizeof(int));
}

int	main(void)
{
	int	*stack_a;
	int	*stack_b;
	int	a_size;
	int	b_size;
	int	i;

	a_size = 3;
	b_size = 2;
	stack_a = ft_calloc(5, sizeof(int));
	stack_b = ft_calloc(5, sizeof(int));
	stack_a[0] = 1;
	stack_a[1] = 2;
	stack_a[2] = 3;
	stack_b[0] = 4;
	stack_b[1] = 5;
	pa(stack_a, &a_size, stack_b, &b_size);
	i = 0;
	while (i < a_size)
		ft_printf("%d", stack_a[i++]);
	ft_printf("\n");
	i = 0;
	while (i < b_size)
		ft_printf("%d", stack_b[i++]);
	return (0);
}
