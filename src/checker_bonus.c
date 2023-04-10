/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:51:16 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/10 13:01:26 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	check_move(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		sa(stack_a, stack_b);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		sb(stack_a, stack_b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ra(stack_a, stack_b);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rb(stack_a, stack_b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(move, "rra\n", 3) == 0)
		rra(stack_a, stack_b);
	else if (ft_strncmp(move, "rrb\n", 3) == 0)
		rrb(stack_a, stack_b);
	else if (ft_strncmp(move, "rrr\n", 3) == 0)
		rrr(stack_a, stack_b);
	else
		(ft_printf("\033[0;31mError\n\033[0m"), exit(-1));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*move;

	stack_a = validator(argc, argv);
	stack_b = NULL;
	move = get_next_line(0);
	while (move != NULL)
	{
		check_move(move, &stack_a, &stack_b);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (ft_issorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&stack_a);
	free_stacks(&stack_b);
	return (0);
}
