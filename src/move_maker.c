/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:28 by uclement          #+#    #+#             */
/*   Updated: 2023/06/02 13:53:39 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	move(t_stack **stack_a, t_stack **stack_b, int call)
{
	if (call == 1 || call == 2)
		pair_swap(stack_a);
	else if (call == 3)
		double_move(stack_a, stack_b, call);
	else if (call == 4)
		push(stack_a, stack_b);
	else if (call == 5)
		push(stack_b, stack_a);
	else if (call == 6 || call == 7)
		rotate(stack_a);
	else if (call == 8)
		double_move(stack_a, stack_b, call);
	if (call == 9 || call == 10)
		reverse(stack_a);
	else if (call == 11)
		double_move(stack_a, stack_b, call);
	print_move(call);
}

void	double_move(t_stack **stack_a, t_stack **stack_b, int call)
{
	if (call == 3)
	{
		pair_swap(stack_a);
		pair_swap(stack_b);
	}
	else if (call == 8)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (call == 11)
	{
		reverse(stack_a);
		reverse(stack_b);
	}
}

void	print_move(int call)
{	
	if (call == 1)
		write(1, "sa\n", 3);
	if (call == 2)
		write(1, "sb\n", 3);
	if (call == 3)
		write(1, "ss\n", 3);
	if (call == 4)
		write(1, "pa\n", 3);
	if (call == 5)
		write(1, "pb\n", 3);
	if (call == 6)
		write(1, "ra\n", 3);
	if (call == 7)
		write(1, "rb\n", 3);
	if (call == 8)
		write(1, "rr\n", 3);
	if (call == 9)
		write(1, "rra\n", 4);
	if (call == 10)
		write(1, "rrb\n", 4);
	if (call == 11)
		write(1, "rrr\n", 4);
}
