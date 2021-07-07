/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:10:51 by saelee            #+#    #+#             */
/*   Updated: 2021/06/08 19:10:53 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	char	**tmp;
	int		a_size;
	int		b_size;
	int		args;
	int		s_max_lis;
	int		*lis;
	int		*lis_flag;
}				t_stack;

int		main(int argc, char **argv);
int		is_in_order(t_stack *stack);
void	parsing_arguments(int argc, char **argv, t_stack *stack);
int		arg_count(char **argv, t_stack *stack);
int		is_space(char **argv, int i);
int		min_in_stack(t_stack *stack);
void	algorithm(t_stack *stack);
void	three_numbers(t_stack *stack);
void	lis(t_stack *stack);
void	find_lis(t_stack *stack, int lis_flag[]);
int		right_nb(t_stack *stack);
void	repush(t_stack *stack);
int		right_spot(t_stack *stack, int i);
int		bigger_than_stack_a(t_stack *stack, int i);
int		max_in_stack(t_stack *stack);
int		smaller_than_stack_a(t_stack *stack, int i);
int		is_decrescent(t_stack *stack);
void	the_last_command(t_stack *stack);
void	decrescent_algorithm(t_stack *stack);
void	rr_ra(t_stack *stack, int i, int j);
void	ra_rrb(t_stack *stack, int i, int j);
void	rrr_rra(t_stack *stack, int i, int j);
void	rr_rb(t_stack *stack, int i, int j);
void	rra_rb(t_stack *stack, int i, int j);
void	rrr_rrb(t_stack *stack, int i, int j);
int		count_moves(t_stack *stack, int i, int j);
int		combination(t_stack *stack, int i);
void	choose_algorithm(t_stack *stack);
void	sequence(t_stack *stack, int *lis_flag, int size);
char	**ft_split(char *s, const char needle);
void	*ft_calloc(size_t size, size_t num);
void	*ft_bzero(void *str, size_t len);
int		ft_atoi(const char *str, t_stack *stack);
int		ft_isdigit(int c);
void	swap_a(t_stack *stack);
void	rotate_a(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	swap_b(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	rotate_b(t_stack *stack);
void	reverse_rotate_both(t_stack *stack);
void	rotate_both(t_stack *stack);
void	swap_both(t_stack *stack);
void	double_checker(t_stack *stack);
int		get_next_line(char **line);
int		only_integers(int argc, char **argv);
void	take_commands(t_stack *stack, char *line);

#endif