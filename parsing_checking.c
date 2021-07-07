/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:10:33 by saelee            #+#    #+#             */
/*   Updated: 2021/06/15 03:56:00 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_integers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write (1, "Error\n", 6);
				exit (0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

void	double_checker(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->args - 1)
	{
		j = i + 1;
		while (j < stack->args)
		{
			if (stack->a[i] == stack->a[j])
			{
				write(1, "Error\n", 6);
				free(stack->a);
				free(stack->b);
				exit (1);
			}
			else
				j++;
		}
		i++;
	}
}

int	ft_space(char **argv, int i)
{
	int	y;
	int	size;

	y = 0;
	size = 0;
	while (argv[i][y])
	{
		if (argv[i][y] != ' ' && argv[i][y + 1] == ' ')
		{	
			size++;
			y++;
			while (argv[i][y] == ' ')
			{
				if (!(argv[i][y + 1]))
					return (size);
				y++;
			}
		}
		else
			y++;
	}
	if (size == 0)
		return (0);
	return (size + 1);
}

void	parsing_arguments(int argc, char **argv, t_stack *stack)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 1;
	j = 0;
	while (i < argc)
	{	
		if (ft_space(argv, i))
		{	
			stack->tmp = malloc(ft_space(argv, i) * sizeof(char *));
			stack->tmp = ft_split(argv[i], ' ');
			y = j;
			x = 0;
			while (j < ft_space(argv, i) + y)
				stack->a[j++] = ft_atoi(stack->tmp[x++], stack);
			free(stack->tmp);
		}
		else
			stack->a[j++] = ft_atoi(argv[i], stack);
		i++;
	}
}

int	arg_count(char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	stack->args = 0;
	while (argv[i])
	{
		if (ft_space(argv, i))
			stack->args += ft_space(argv, i);
		else
			stack->args++;
		i++;
	}
	return (stack->args);
}
