/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:53:31 by uclement          #+#    #+#             */
/*   Updated: 2023/06/16 11:54:09 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

t_stack	*create_stack(int content)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->index = 0;
	stack->next = NULL;
	return (stack);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

int	to_list_a(char **argv, int argc, t_stack **stack_a)
{
	long long int	nbr;
	t_stack			*new_node;
	int				i;

	i = 0;
	while (++i < argc)
	{
		nbr = ps_atoi(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_exit();
		if (i == 1)
			*stack_a = create_stack(nbr);
		else
		{
			new_node = create_stack(nbr);
			ps_lstadd_front(stack_a, new_node);
		}
	}
	if (argc == 2)
	{
		write (1, "OK\n", 3);
		free_lst(stack_a);
		return (1);
	}
	return (0);
}

int	is_sort(t_stack *a)
{
	while (a->content > a->next->content)
	{
		a = a->next;
		if (a->next == NULL)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (to_list_a(argv, argc, &stack_a) == 1)
		return (0);
	doublon(stack_a);
	line = get_next_line(0);
	while (line)
	{
		apply_function(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sort(stack_a) == 1)
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}
