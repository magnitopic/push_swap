/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/24 17:06:52 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		*aux;

	i = 1;
	stack_b = NULL;
	aux = malloc(sizeof(int));
	*aux = ft_atoi(argv[i++]);
	stack_a = ft_lstnew(&*aux);
	while (i < argc)
	{
		aux = malloc(sizeof(int));
		*aux = ft_atoi(argv[i++]);
		ft_lstadd_back(&stack_a, ft_lstnew(&*aux));
	}
	ft_lstprint_int(stack_a);
	sa(&stack_a, &stack_b);
	ft_printf("\n");
	ft_lstprint_int(stack_a);
	/* ft_printf("\n%s\n", sa(stack_a, stack_b));
	ft_lstprint_int(stack_a); */
}
