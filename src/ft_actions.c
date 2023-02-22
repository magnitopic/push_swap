/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:07 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/22 18:55:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
/* 
void	swap(t_list **a)
{
	if (ft_lstsize(a) > 1)
	{
		a* -> content;
	}
}

void	push(t_list **a, t_list **b)
{
	
}

void	ft_rotate(int *stack_a, int *a_size)
{
	int	aux;
	int	i;

	if (*a_size < 1)
		return ;
	aux = stack_a[0];
	i = 0;
	while (i < *a_size)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[*a_size - 1] = aux;
}

void	ft_reverse_rotate(int *stack_a, int *a_size)
{
	int	aux;
	int	i;

	if (*a_size < 1)
		return ;
	aux = stack_a[*a_size - 1];
	i = *a_size - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = aux;
}
 */


/* int	main(void)
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
	ft_swap(stack_a, a_size);
	//ft_push(stack_a, &a_size, stack_b, total_size - a_size);
	//ft_rotate(stack_a, &a_size);
	//ft_reverse_rotate(stack_a, &a_size);
	i = 0;
	while (i < a_size)
		ft_printf("%d", stack_a[i++]);
	ft_printf("\n");
	i = 0;
	while (i < total_size - a_size)
		ft_printf("%d", stack_b[i++]);
	ft_printf("\n");
	return (0);
} */
