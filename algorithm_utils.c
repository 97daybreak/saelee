/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:09:55 by saelee            #+#    #+#             */
/*   Updated: 2021/07/07 04:34:02 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//b에 있는 원소 stack a에 넣을 위치 찾기
int	right_spot(t_stack *stack, int i)
{
	int	j;

	j = 0;
	//a에 있는 것들 보다 제일 크다면 max갱신
	if (bigger_than_stack_a(stack, i))
		return (max_in_stack(stack) + 1);
	//a에 있는 것들 보다 제일 작다면 min갱신
	if (smaller_than_stack_a(stack, i))
		return (min_in_stack(stack));
	//그렇지 않다면 a에서 들어갈 위치 찾기 사이에 넣기
	while (j < stack->a_size)
	{
		if (stack->b[i] > stack->a[j] && stack->b[i] < stack->a[j + 1])
			return (j + 1);
		j++;
	}
	return (0);
}

int	combination(t_stack *stack, int i)
{
	while (i < stack->b_size)
	{
		//b가 들어가야 할 시점이 a의 반 사이즈보다 작다면 
		//b의 갯수에 따라 달라짐
		if (right_spot(stack, i) < stack->a_size / 2)
		{
			
			if (i <= stack->b_size / 2)
				return (1);
			return (2);
		}
		else
		{
			if (i < stack->b_size / 2)
				return (3);
			return (4);
		}
	}
	return (0);
}

int	count_moves(t_stack *stack, int i, int j)
{
	int	count;
	//printf("[%d]",combination(stack,i));
	// i = 0, j = 0
	if (combination(stack, i) == 1)
	{
		if (j > i)
			count = j;
		else
			count = i;
		//printf("[%d]",count);
	}
	else if (combination(stack, i) == 2)
		count = j + (stack->b_size - i);
	else if (combination(stack, i) == 3)
		count = stack->a_size - j + i - 1;
	else
	{
		if ((stack->a_size - j) > (stack->b_size - i))
			count = stack->a_size - j;
		else
			count = stack->b_size - i;
	}
	return (count);
}

int	right_nb(t_stack *stack)
{
	int	i;
	int	index;
	int	count;
	int	count2;
	int	j;

	i = 0;
	index = 0;
	count2 = 32000;
	while (i < stack->b_size)
	{
		j = right_spot(stack, i);	//j = 0
		count = count_moves(stack, i, j);	//count = 0
		//printf("count : %d\n",count);
		if (count < count2)
		{
			count2 = count;
			index = i;
			//printf("index : %d\n",index);
		}
		i++;
	}
	return (index);
}

void	repush(t_stack *stack)
{
	int	i;
	int	j;

	i = right_nb(stack);	//0
	j = right_spot(stack, i);	//0
	if (combination(stack, i) == 1)
	{
		if (i <= j)
			rr_ra(stack, i, j);
		else
			rr_rb(stack, i, j);
	}
	else if (combination(stack, i) == 4)
	{
		if ((stack->b_size - i) < (stack->a_size - j))
			rrr_rra(stack, i, j);
		else
			rrr_rrb(stack, i, j);
	}
	else if (combination(stack, i) == 2)
		ra_rrb(stack, i, j);
	else
		rra_rb(stack, i, j);
	push_a(stack);
	write(1, "pa\n", 3);
}
