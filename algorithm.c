/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:10:02 by saelee            #+#    #+#             */
/*   Updated: 2021/07/05 04:30:39 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_last_command(t_stack *stack)
{
	while (stack->b_size > 0)
		repush(stack);
	//뒤에 작은 숫자가 남아 있다면
	while (min_in_stack(stack) > 0)
	{
		//뒤에 작은 숫자가 남아있지만 반을 기준으로 앞쪽에 있다면 
		if (min_in_stack(stack) <= stack->a_size / 2)
		{
			rotate_a(stack);
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate_a(stack);
			write(1, "rra\n", 4);
		}
	}
	return ;
}

void	lis(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	stack->s_max_lis = 0;
	stack->lis = malloc(stack->a_size * sizeof(int));
	while (i < stack->a_size)
		stack->lis[i++] = 1;
	/*
	i =0;
	while(i<stack->a_size)
	{
		printf("lis[%d] : %d\n",i, stack->lis[i]);
		i++;
	}
	*/
	i = 0;
	while (j < stack->a_size)
	{
		i = j;
		while (i < stack->a_size)
		{
			if (stack->a[j] < stack->a[i] && stack->lis[j] == stack->lis[i])
			{
				stack->lis[i] += 1;
				printf("stack->lis[%d] : %d\n", i, stack->lis[i]);
				if (stack->lis[i] > stack->s_max_lis)
					stack->s_max_lis = stack->lis[i];
				printf("max : %d\n", stack->lis[i]);
			}
			i++;
		}
		j++;
	}
	/*
	i =0;
	while(i<stack->a_size)
	{
		printf("lis[%d] : %d\n",i, stack->lis[i]);
		i++;
	}
	*/
}

// 순서 다른거 찾기
void	find_lis(t_stack *stack, int *lis_flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// 초기화 
	while (i < stack->a_size)
	{
		lis_flag[i] = 0;
		i++;
	}
	i = 0;
	while (stack->lis[i] != stack->s_max_lis)
		i++;
	//printf("[%d]",i);
	while (i >= 0)
	{
		if (stack->lis[i] == (stack->s_max_lis - j))
		{
			//printf("stack->s_max_lis - j : %d\n", stack->s_max_lis - j);
			//printf("\nstack->lis[%d] : %d\n",i,stack->lis[i]);
			lis_flag[i] = 1;
			j++;
		}
		i--;
	}
	/*
	int k = 0;
	while(k<4)
	{
		printf("lis_flag[%d] : %d\n", k,lis_flag[k]);
		k++;
	}
	*/
}

void	sequence(t_stack *stack, int *lis_flag, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (lis_flag[i] == 1)
		{
			rotate_a(stack);
			write(1, "ra\n", 3);
		}
		else
		{
			push_b(stack);
			write(1, "pb\n", 3);
		}
		i++;
	}
}

void	algorithm(t_stack *stack)
{
	int	i;
	int	size;
	int	*lis_flag;

	i = 0;
	size = stack->a_size;
	lis(stack);
	lis_flag = malloc(size * sizeof(int));
	find_lis(stack, lis_flag);
	free(stack->lis);
	sequence(stack, lis_flag, size);
	free(lis_flag);
	the_last_command(stack);
	return ;
}
