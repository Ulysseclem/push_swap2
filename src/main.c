/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:45:52 by uclement          #+#    #+#             */
/*   Updated: 2023/06/19 13:34:17 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*create_stack(int content)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->next = NULL;
	return (stack);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	to_list_a(char **argv, int argc, t_stack **stack_a)
{
	long long int	nbr;
	t_stack			*new_node;
	int				i;

	i = 1;
	while (i < argc)
	{
		nbr = ps_atoi(argv[i], stack_a);
		if (i == 1)
			*stack_a = create_stack(nbr);
		else
		{
			new_node = create_stack(nbr);
			ps_lstadd_front(stack_a, new_node);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	to_list_a(argv, argc, &stack_a);
	if (argc < 2)
		return (0);
	if (parsing(&stack_a) == 0)
		return (0);
	else
	{
		index_maker(&stack_a);
		median_sort(&stack_a, &stack_b);
		while (stack_b)
			iter_index(&stack_a, &stack_b);
		last_sort(&stack_a, &stack_b);
	}
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}
