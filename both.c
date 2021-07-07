/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:09:46 by saelee            #+#    #+#             */
/*   Updated: 2021/06/24 03:41:29 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rrr
void	reverse_rotate_both(t_stack *stack)
{
	reverse_rotate_b(stack);
	reverse_rotate_a(stack);
}

//rr
void	rotate_both(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

//ss
void	swap_both(t_stack *stack)
{
	swap_b(stack);
	swap_a(stack);
}
