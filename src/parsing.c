/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:08:42 by uclement          #+#    #+#             */
/*   Updated: 2023/06/12 15:00:48 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	doublon(t_stack	*lst)
{
	t_stack	*tmp;

	while (lst->next != NULL)
	{
		tmp = lst->next;
		while (tmp != NULL)
		{
			if (lst->content == tmp->content)
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}

int	is_sort(t_stack *a)
{
	if (a->next == NULL)
		return (0);
	while (a->content > a->next->content)
	{
		a = a->next;
		if (a->next == NULL)
			return (0);
	}
	return (1);
}
