/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:08:42 by uclement          #+#    #+#             */
/*   Updated: 2023/06/19 13:34:00 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	parsing(t_stack **a)
{
	if (doublon(*a) == 0)
	{
		free_lst(a);
		error_exit();
	}
	if (is_sort(a) == 0)
	{
		free_lst(a);
		return (0);
	}
	return (1);
}

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

int	is_sort(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (tmp->next == NULL)
		return (0);
	while (tmp->content > tmp->next->content)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (0);
	}
	if (ps_lstsize(*a) == 2)
	{
		move(a, NULL, 1);
		return (0);
	}
	return (1);
}

int	ps_atoi(const char *nptr, t_stack **a)
{
	int		i;
	int		neg;
	int		nbr;

	i = 0;
	neg = 1;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] == '0' && nptr[i + 1] != '\0')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
	{
		free_lst (a);
		error_exit();
	}
	nbr = ps_atoi_suite(nptr, i, neg, a);
	return (nbr);
}

int	ps_atoi_suite(const char *nptr, int i, int neg, t_stack **a)
{
	long long int	num;
	int				j;
	int				test;

	num = 0;
	j = 0;
	while (nptr[i] != '\0')
	{
		if (nptr[i] < '0' || nptr[i] > '9' || j > 10)
		{
			free_lst (a);
			error_exit();
		}
		num = num * 10 + (nptr[i] - 48);
		j++;
		i++;
	}
	if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
		error_exit();
	test = num;
	return (test * neg);
}
