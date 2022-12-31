/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:21:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/01/01 00:51:50 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <time.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		*random_stack(int amount);
void	sa(int *stack_a, int a_size);
void	sb(int *stack_b, int b_size);
void	ss(int *stack_a, int a_size, int *stack_b, int b_size);
void	pa(int *stack_a, int *a_size, int *stack_b, int b_size);

#endif