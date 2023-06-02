/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:12:39 by uclement          #+#    #+#             */
/*   Updated: 2023/06/02 14:38:54 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

long long int	ps_atoi(const char *nptr)
{
	long long int	num;
	int				i;
	long long int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] == '0')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		if (nptr[i] < '0' && nptr[i] > '9')
			error_exit();
		i++;
	}
	return (num * neg);
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
