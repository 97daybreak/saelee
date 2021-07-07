/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:10:13 by saelee            #+#    #+#             */
/*   Updated: 2021/06/24 03:31:30 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_while(char **line, char buffer[], int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		(*line)[j] = buffer[j];
		buffer[j] = 0;
		j++;
	}
	(*line)[j] = 0;
}

//끝까지 읽음 0 한줄읽음 1 에러 -1
int	get_next_line(char **line)
{
	int		i;
	int		red;
	char	buffer[1024*1024];

	i = 0;
	red = read(0, &buffer[i], 1);
	while (red >= 0)
	{
		if (buffer[i] == '\n' || buffer[i] == 0)
		{
			buffer[i] = 0;
			*line = malloc(i);
			if (!(*line))
				return (-1);
			ft_while(line, buffer, i);
			if (red == 0)
				return (0);
			else
				return (1);
		}
		i++;
		red = read(0, &buffer[i], 1);
	}
	return (-1);
}

int	are_command(t_stack *stack, char *line)
{
	if (line[0] == 'p' && line[1] == 'a' && !line[2])
		push_a(stack);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\0')
		swap_a(stack);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\0')
		rotate_a(stack);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && !line[3])
		reverse_rotate_a(stack);
	else if (line[0] == 'p' && line[1] == 'b' && !line[2])
		push_b(stack);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\0')
		swap_b(stack);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\0')
		rotate_b(stack);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && !line[3])
		reverse_rotate_b(stack);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && !line[3])
		reverse_rotate_both(stack);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\0')
		rotate_both(stack);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\0')
		swap_both(stack);
	else
		return (0);
	return (1);
}

void	take_commands(t_stack *stack, char *line)
{
	while (get_next_line(&line) > 0)
	{
		if (!(are_command(stack, line)))
		{
			write(1, "Error\n", 6);
			free(line);
			free(stack->a);
			free(stack->b);
			exit (0);
		}
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	*line;

	line = NULL;
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
	double_checker(&stack);	//중복 숫자 확인
	take_commands(&stack, line);	//error처리
	if (!(is_in_order(&stack)))
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	free(stack.a);
	free(stack.b);
	return (1);
}
