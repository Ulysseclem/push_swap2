/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:08:42 by uclement          #+#    #+#             */
/*   Updated: 2023/06/16 11:50:05 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	doublon(t_stack	*lst)
{
	t_stack	*tmp;

	while (lst->next != NULL)
	{
		tmp = lst->next;
		while (tmp != NULL)
		{
			if (lst->content == tmp->content)
				error_exit();
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

int	ps_atoi(const char *nptr)
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
		error_exit();
	nbr = ps_atoi_suite(nptr, i, neg);
	return (nbr);
}

int	ps_atoi_suite(const char *nptr, int i, int neg)
{
	long long int	num;
	int				j;
	int				test;

	num = 0;
	j = 0;
	while (nptr[i] != '\0')
	{
		if (nptr[i] < '0' || nptr[i] > '9' || j > 10)
			error_exit();
		num = num * 10 + (nptr[i] - 48);
		j++;
		i++;
	}
	if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
		error_exit();
	test = num;
	return (test * neg);
}
