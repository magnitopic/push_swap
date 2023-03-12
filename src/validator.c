/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:47:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/12 18:22:19 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	no_repeating_values(t_stack *stack_a, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (get(stack_a, i)->value == get(stack_a, j)->value)
				(ft_printf("\033[0;31mError\n\033[0m"), exit(-1));
			j++;
		}
		i++;
	}
}

static t_stack	*create_stack(char **numbers)
{
	t_stack	*stack_a;
	int		i;
	int		*aux;

	stack_a = NULL;
	i = 0;
	aux = malloc(sizeof(int));
	*aux = ft_atoi(numbers[i++]);
	stack_a = add_new(stack_a, *aux);
	while (numbers[i] != NULL)
	{
		aux = malloc(sizeof(int));
		*aux = ft_atoi(numbers[i++]);
		add_new(stack_a, *aux);
	}
	return (stack_a);
}

static char	*parser(char **value)
{
	int		i;
	int		j;
	char	*lst;

	i = 0;
	lst = "";
	while (value[i] != NULL)
	{
		j = 0;
		if ((value[i][0] == '-' || value[i][0] == '+')
			&& ft_strlen(value[i]) > 1)
			j++;
		while (value[i][j] != '\0')
		{
			if (!ft_isdigit(value[i][j]))
				(ft_printf("\033[0;31mError\n\033[0m"), exit(-1));
			j++;
		}
		lst = ft_strjoin(ft_strjoin(lst, value[i]), " ");
		i++;
	}
	return (lst);
}

t_stack	*validator(int argc, char **argv)
{
	char	*lst;
	t_stack	*stack_a;
	int		i;

	if (argc <= 1)
		return (NULL);
	lst = "";
	i = 1;
	while (i < argc)
	{
		if (!ft_strlen(argv[i]))
			(ft_printf("\033[0;31mError\n\033[0m"), exit(-1));
		lst = ft_strjoin(lst, parser(ft_split(argv[i++], ' ')));
	}
	stack_a = create_stack(ft_split(lst, ' '));
	no_repeating_values(stack_a, stack_size(stack_a));
	return (stack_a);
}
