/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:09:34 by saelee            #+#    #+#             */
/*   Updated: 2021/06/08 19:09:39 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	tmp;

	if (stack->a_size >= 2)
	{
		tmp = stack->a[1];
		stack->a[1] = stack->a[0];
		stack->a[0] = tmp;
	}
}

void	rotate_a(t_stack *stack)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = stack->a[0];
	while (i < stack->a_size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->a_size - 1] = tmp;
}

void	reverse_rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->a_size - 1;
	tmp = stack->a[stack->a_size - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
}

void	push_a_continue(t_stack *stack, int *tmp)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->a[i + 1] = tmp[i];
		i++;
	}
	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
}

void	push_a(t_stack *stack)
{
	int	*tmp;
	int	i;

	if (!(stack->b_size))
		return ;
	i = 0;
	tmp = malloc(stack->a_size * sizeof(int));
	while (i < stack->a_size)
	{
		tmp[i] = stack->a[i];
		i++;
	}
	stack->a[0] = stack->b[0];
	stack->a_size++;
	push_a_continue(stack, tmp);
	free (tmp);
	stack->b_size--;
}
