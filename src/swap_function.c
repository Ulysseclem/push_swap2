/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:37:03 by uclement          #+#    #+#             */
/*   Updated: 2023/06/01 11:15:06 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pair_swap(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;
	t_stack	*last;

	prev = NULL;
	current = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (current->next->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	last = current->next;
	current->next = NULL;
	last->next = current;
	if (prev != NULL)
		prev->next = last;
	else
		*stack = last;
}

void	push(t_stack **receiver, t_stack **sender)
{
	t_stack	*curr;

	if (*sender == NULL)
		return ;
	if ((*sender)->next == NULL)
	{
		if (*receiver == NULL)
			*receiver = *sender;
		else
		{
			curr = ps_lstlast(*receiver);
			curr->next = *sender;
		}
		*sender = NULL;
		return ;
	}
	curr = *sender;
	push_suite(receiver, curr);
}

void	push_suite(t_stack **receiver, t_stack *curr)
{
	t_stack	*prev;
	t_stack	*tmp;

	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	if (*receiver == NULL)
		*receiver = curr;
	else
	{
		tmp = ps_lstlast(*receiver);
		tmp->next = curr;
	}
	prev->next = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	end = ps_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = tmp;
	(*stack)->next = NULL;
	*stack = end;
}

void	reverse(t_stack	**stack)
{
	t_stack	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ps_lstlast(*stack)->next = head;
}
