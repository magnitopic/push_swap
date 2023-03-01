/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/01 16:28:53 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		*aux;

	if (argc <= 1)
		return (0);
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
	ft_printf("%s", busca(stack_a, stack_b));
	return (0);
}
