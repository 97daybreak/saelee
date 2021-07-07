/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:10:07 by saelee            #+#    #+#             */
/*   Updated: 2021/06/08 19:10:09 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *stack)
{
	int	tmp;

	if (stack->b_size >= 2)
	{
		tmp = stack->b[1];
		stack->b[1] = stack->b[0];
		stack->b[0] = tmp;
	}
}

void	rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->b[0];
	while (i < stack->b_size)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->b_size - 1] = tmp;
}

void	reverse_rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->b_size - 1;
	tmp = stack->b[stack->b_size - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
}

void	push_b_continue(t_stack *stack, int *tmp)
{
	int	i;

	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->b[i + 1] = tmp[i];
		i++;
	}
	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
}

void	push_b(t_stack *stack)
{
	int	*tmp;
	int	i;

	i = 0;
	if (!(stack->a_size))
		return ;
	tmp = malloc(stack->b_size * sizeof(int));
	while (i < stack->b_size)
	{
		tmp[i] = stack->b[i];
		i++;
	}
	stack->b[0] = stack->a[0];
	stack->b_size++;
	push_b_continue(stack, tmp);
	free(tmp);
	stack->a_size--;
}
