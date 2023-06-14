/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:12:39 by uclement          #+#    #+#             */
/*   Updated: 2023/06/13 16:44:14 by ulysse           ###   ########.fr       */
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

// int	ps_atoi(const char *nptr)
// {
// 	long long int	num;
// 	int				i;
// 	int				test;
// 	int				neg;

// 	i = 0;
// 	num = 0;
// 	neg = 1;
// 	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == 32 || \
// 	nptr[i] == '+' || nptr[i] == '-' )
// 	{
// 		if (nptr[i] == '-')
// 			neg = -1;
// 		i++;
// 	}
// 	while (nptr[i] != '\0')
// 	{
// 		num = num * 10 + (nptr[i] - 48);
// 		if (nptr[i] < '0' || nptr[i] > '9')
// 			error_exit();
// 		i++;
// 	}
// 	if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
// 		error_exit();
// 	test = num;
// 	return (test * neg);
// }

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
