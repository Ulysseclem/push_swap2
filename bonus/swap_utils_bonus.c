/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:12:39 by uclement          #+#    #+#             */
/*   Updated: 2023/06/16 11:49:58 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	free_lst(t_stack	**lst)
{
	t_stack	*tmp;

	while ((*lst) != NULL)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ps_lstsize(t_stack *lst)
{
	int		i;

	i = 0;
	if (lst == NULL)
		return (i);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	apply_function(t_stack **a, t_stack **b, char *readed)
{
	if (ft_strncmp (readed, "sa\n", 3) == 0)
		pair_swap(a);
	else if (ft_strncmp (readed, "sb\n", 3) == 0)
		pair_swap(b);
	else if (ft_strncmp (readed, "pa\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp (readed, "pb\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp (readed, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp (readed, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp (readed, "rra\n", 4) == 0)
		reverse(a);
	else if (ft_strncmp (readed, "rrb\n", 4) == 0)
		reverse(b);
}
