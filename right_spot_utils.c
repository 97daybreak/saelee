/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_spot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:11:11 by saelee            #+#    #+#             */
/*   Updated: 2021/06/24 03:38:44 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 순서대로 되어있는지 확인 true 1 false 0
int	is_in_order(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->b_size == 0)
	{
		while (i < stack->a_size - 1)
		{
			if (stack->a[i] < stack->a[i + 1])
				i++;
			else
				break ;
		}
		if (i == (stack->a_size - 1))
			return (1);
		return (0);
	}
	return (0);
}

//b에 있는 숫자가 a와 비교했을때 작으면 1 크면 0
int	smaller_than_stack_a(t_stack *stack, int i)
{
	int	j;

	j = 0;
	while (j < stack->a_size)
	{
		if (stack->b[i] > stack->a[j])
			return (0);
		j++;
	}
	return (1);
}

//stack a에서 제일 큰 index(숫자, 자리) 찾기
int	max_in_stack(t_stack *stack)
{
	int	j;
	int	index;
	int	max;

	j = 0;
	index = 0;
	max = 0;
	while (j < stack->a_size)
	{
		if (stack->a[j] > max)
		{
			max = stack->a[j];
			index = j;
		}
		j++;
	}
	return (index);
}

//stack a에서 제일 작은 index(숫자, 자리) 찾기
int	min_in_stack(t_stack *stack)
{
	int	j;
	int	index;
	int	min;

	index = 0;
	min = stack->a[0];
	j = 0;
	while (j < stack->a_size)
	{
		if (stack->a[j] < min)
		{
			min = stack->a[j];
			index = j;
		}
		j++;
	}
	//printf("min : %d\n",min);
	return (index);
}

//b에 있는 숫자가 stack a에 있는 것들과 비교했을 때 크면 1 작으면 0
int	bigger_than_stack_a(t_stack *stack, int i)
{
	int	j;

	j = 0;
	while (j < stack->a_size)
	{
		if (stack->b[i] < stack->a[j])
			return (0);
		j++;
	}
	return (1);
}
