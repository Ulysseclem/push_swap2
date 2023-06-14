/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:39:18 by uclement          #+#    #+#             */
/*   Updated: 2023/06/13 14:19:00 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	index_maker(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*first;
	int		i;

	first = *stack;
	tmp = (*stack)->next;
	while ((*stack) != NULL)
	{		
		i = 1;
		while (tmp != NULL)
		{
			if (((*stack)->content) > (tmp->content))
				i++;
			tmp = tmp->next;
		}
		tmp = first;
		(*stack)->index = i;
		*stack = (*stack)->next;
	}
	*stack = first;
}

void	median_sort(t_stack **a, t_stack **b)
{
	int		size;
	int		i;
	t_stack	*current;
	t_stack	*last;

	size = ps_lstsize(*a);
	while (ps_lstsize(*a) > 3)
	{
		i = 0;
		while (i < size)
		{
			current = *a;
			last = ps_lstlast(current);
			if (last->index > (size / 2))
				move(a, b, 5);
			else
				move(a, b, 6);
			i++;
			if (ps_lstsize(*a) == 3)
				break;
		}
		size = ps_lstsize(*a);
	}
	three(a, b);
}

void	three(t_stack **a, t_stack **b)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->next->next->content;
	mid = (*a)->next->content;
	bot = (*a)->content;
	if (bot > mid && bot < top && mid < top)
		move(a, b, 6);
	else if (bot < mid && bot < top && mid < top)
	{
		move(a, b, 1);
		move(a, b, 9);
	}
	else if (bot > mid && bot > top && mid < top)
		move(a, b, 1);
	else if (bot < mid && bot > top && mid > top)
	{
		move(a, b, 1);
		move(a, b, 6);
	}
	else if (bot < mid && bot < top && mid > top)
		move(a, b, 9);
}
