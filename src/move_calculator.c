/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:49:48 by uclement          #+#    #+#             */
/*   Updated: 2023/06/19 11:08:38 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/* calcul le nombre de coup pour acceder a un nombre*/

void	iter_index(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		i;
	int		j;

	i = 1;
	current = *b;
	while (current != NULL)
	{
		if (i <= (ps_lstsize(*b) / 2))
		{
			j = i + 1;
			while (--j)
				calculateur(b, 10);
		}
		else
		{
			j = ps_lstsize(*b) - i + 1;
			while (--j)
				calculateur(b, 7);
		}
		index_find_pos(a, &current);
		i++;
		current = current->next;
	}
	search_index_min(a, b);
}

/*cherche la position ou placer le nombre de stack_b*/

void	index_find_pos(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		count;
	int		nbr;

	current = *a;
	count = 1;
	nbr = (*b)->content;
	while (current->next != NULL)
	{
		if (nbr < current->content && \
		(current->next == NULL || nbr > current->next->content))
			break ;
		if (current->content < current->next->content && \
		nbr > current->next->content)
			break ;
		count++;
		current = current->next;
	}
	index_sort(a, b, count);
}

/*trie la stack a pour pouvoir positionner le nombre B*/

void	index_sort(t_stack **a, t_stack **b, int count)
{
	if (count <= (ps_lstsize(*a) / 2))
	{
		while (count != 0)
		{
			calculateur(b, 9);
			count--;
		}
		calculateur(b, 4);
	}
	else
	{
		count = ps_lstsize(*a) - count;
		while (count != 0)
		{
			calculateur(b, 6);
			count--;
		}
		calculateur(b, 4);
	}
}
