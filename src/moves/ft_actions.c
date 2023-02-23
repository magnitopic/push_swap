/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:33:07 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/23 18:22:24 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*swap(t_list *stack1, t_list *stack2)
{
	t_list	aux;

	aux = stack1[ft_lstsize(stack1)-1];
	return ("sa");
}

int	main(int argc, char **argv)
{
	t_list	*listita;
	int		i;
	int		*aux;

	i = 1;
	aux = malloc(sizeof(int));
	*aux = ft_atoi(argv[i++]);
	listita = ft_lstnew(&*aux);
	while (i < argc)
	{
		aux = malloc(sizeof(int));
		*aux = ft_atoi(argv[i++]);
		ft_lstadd_back(&listita, ft_lstnew(&*aux));
	}
	ft_lstprint_int(listita);
}
