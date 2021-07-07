/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:10:43 by saelee            #+#    #+#             */
/*   Updated: 2021/06/14 13:55:44 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void three_numbers(t_stack *stack)
{
	if (stack->a[2] < stack->a[1] && stack->a[1] < stack->a[0])
		decrescent_algorithm(stack);
	else if (stack->a[1] < stack->a[0] && stack->a[0] < stack->a[2])
	{
		swap_a(stack);
		write(1, "sa\n", 3);
	}
	else if (stack->a[1] < stack->a[2] && stack->a[2] < stack->a[0])
	{
		rotate_a(stack);
		write(1, "ra\n", 3);
	}
	else if (stack->a[0] < stack->a[2] && stack->a[2] < stack->a[1])
	{
		reverse_rotate_a(stack);
		swap_a(stack);
		write(1, "rra\nsa\n", 7);
	}
	else if (stack->a[2] < stack->a[0] && stack->a[0] < stack->a[1])
	{
		reverse_rotate_a(stack);
		write(1, "rra\n", 4);
	}
}

void decrescent_algorithm(t_stack *stack)
{
	while (stack->a_size > 3)
	{
		reverse_rotate_a(stack);
		push_b(stack);
		write(1, "rra\npb\n", 7);
	}
	rotate_a(stack);
	swap_a(stack);
	write(1, "ra\nsa\n", 6);
	while (stack->b_size > 0)
	{
		push_a(stack);
		write(1, "pa\n", 3);
	}
}

void five_numbers(t_stack *stack)
{
	int i;

	while (stack->a_size > 3)
	{
		i = min_in_stack(stack);
		if (i < 3)
		{
			while (i-- > 0)
			{
				rotate_a(stack);
				write(1, "ra\n", 3);
			}
		}
		else
		{
			while (stack->a_size - i > 0)
			{
				reverse_rotate_a(stack);
				write(1, "rra\n", 4);
				i++;
			}
		}
		push_b(stack);
		write(1, "pb\n", 3);
	}
}

void choose_algorithm(t_stack *stack)
{
	while (!(is_in_order(stack)))
	{
		if (stack->a_size == 2)
		{
			swap_a(stack);
			write(1, "sa\n", 3);
		}
		else if (stack->a_size == 3)
			three_numbers(stack);
		else if (is_decrescent(stack))
			decrescent_algorithm(stack);
		else if (stack->a_size == 5)
		{
			five_numbers(stack);
			three_numbers(stack);
			push_a(stack);
			push_a(stack);
			write(1, "pa\npa\n", 6);
		}
		else
			algorithm(stack);
	}
}

int main(int argc, char **argv)
{
	t_stack stack;

	only_integers(argc, argv);
	if (argc > 1)
	{
		stack.a = malloc(arg_count(argv, &stack) * sizeof(int));
		stack.b = malloc(arg_count(argv, &stack) * sizeof(int));
	}
	else
		return (0);
	stack.b_size = 0;
	stack.a_size = arg_count(argv, &stack);
	parsing_arguments(argc, argv, &stack);
	double_checker(&stack);
	choose_algorithm(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
