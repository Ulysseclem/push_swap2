/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:26:01 by uclement          #+#    #+#             */
/*   Updated: 2023/06/19 13:42:49 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*cherche la position ou placer le nombre de stack_b*/

void	find_pos(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		count;
	int		nbr;

	current = *a;
	count = 1;
	nbr = ps_lstlast(*b)->content;
	while (current->next != NULL)
	{
		if (nbr < current->content && (current->next == NULL || \
		nbr > current->next->content))
			break ;
		if (current->content < current->next->content && \
		nbr > current->next->content)
			break ;
		count++;
		current = current->next;
	}
	sort(a, b, count);
}

/*range a pour pouvoir push B dessus*/

void	sort(t_stack **a, t_stack **b, int count)
{
	if (count <= (ps_lstsize(*a) / 2))
	{
		while (count != 0)
		{
			move(a, b, 9);
			count--;
		}
		move(a, b, 4);
	}
	else
	{
		count = ps_lstsize(*a) - count;
		while (count != 0)
		{
			move(a, b, 6);
			count--;
		}
		move(a, b, 4);
	}
}

void	last_sort(t_stack **stack, t_stack **b)
{
	t_stack	*current;
	int		nbr;
	int		count;

	if (*b != NULL)
		return ;
	current = *stack;
	nbr = current->content;
	count = 1;
	current = current->next;
	while (current != NULL)
	{
		if (current->content < nbr)
			count++;
		else
			break ;
		current = current->next;
	}
	if (count == ps_lstsize(*stack))
		return ;
	last_sort_suite(stack, b, count);
}

void	last_sort_suite(t_stack **stack, t_stack **b, int count)
{
	if (count <= (ps_lstsize(*stack) / 2))
	{
		while (count > 0)
		{
			move(stack, b, 9);
			count--;
		}
	}
	else
	{
		count = ps_lstsize(*stack) - count;
		while (count > 0)
		{
			move(stack, b, 6);
			count--;
		}
	}
}
