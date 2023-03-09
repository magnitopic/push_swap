/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/09 17:21:02 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		*aux;

	if (argc <= 1)
		return (0);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	aux = malloc(sizeof(int));
	*aux = ft_atoi(argv[i++]);
	stack_a = add_new(stack_a, *aux);
	while (i < argc)
	{
		aux = malloc(sizeof(int));
		*aux = ft_atoi(argv[i++]);
		add_new(stack_a, *aux);
	}
	/* if (ft_issorted(stack_a, stack_b))
		return (0);
	if (argc < 7)
		ft_printf("%s", busca(stack_a, stack_b));
	else
		ft_printf("%s", modern_times(stack_a, stack_b)); */
	return (0);
}
