/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:47:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/10 19:04:01 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*validator(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		*aux;

	stack_a = NULL;
	if (argc <= 1)
		return (stack_a);
	i = 1;
	aux = malloc(sizeof(int));
	*aux = ft_atoi(argv[i++]);
	stack_a = add_new(stack_a, *aux);
	while (i < argc)
	{
		aux = malloc(sizeof(int));
		*aux = ft_atoi(argv[i++]);
		add_new(stack_a, *aux);
	}
	return (stack_a);
}

void	funct(int argc, char **argv)
{
	int		i;
	char	*lst;

	i = 1;
	lst = "";
	while (i < argc)
	{
		lst = ft_strjoin(lst, argv[i++]);
		lst = ft_strjoin(lst, " ");
	}
	i = 0;
	while ((size_t)i < ft_strlen(lst))
	{
		if (!ft_isdigit(lst[i++]) && (lst[i] != 32))
			ft_printf("a: %d %d " , ft_isdigit(lst[i]) && (lst[i] != 32), lst[i]);
	}
	ft_printf("\n");
	ft_printf("%s", lst);
}

int	main(int argc, char **argv)
{
	funct(argc, argv);
	return (0);
}
