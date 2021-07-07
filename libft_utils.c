/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:10:25 by saelee            #+#    #+#             */
/*   Updated: 2021/06/08 19:10:26 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_decrescent(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->b_size == 0)
	{
		while (i < stack->a_size - 1)
		{
			if (stack->a[i] > stack->a[i + 1])
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

void	*ft_calloc(size_t size, size_t num)
{
	void	*a;

	a = malloc(size * num);
	if (a)
		ft_bzero(a, size);
	return (a);
}

void	*ft_bzero(void *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = 0;
		i++;
	}
	return (0);
}

int	check(long long x, t_stack *stack)
{
	if (x < -2147483648 || x > 2147483647)
	{
		write (1, "Error\n", 6);
		free (stack->a);
		free (stack->b);
		exit (0);
	}
	return (x);
}

int	ft_atoi(const char *str, t_stack *stack)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == ' ' || str[i] == '\f')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i - 1] == '-' || str[i - 1] == '+')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (check(sign * result, stack));
}
