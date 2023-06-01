/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:53:31 by uclement          #+#    #+#             */
/*   Updated: 2023/06/01 15:54:17 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	main(int argc, char	**argv)
{
	int	i;
	// int		fd;
	char	*line;

	(void)argc;
	(void)argv;
	
	i = 1;
	while (i < argc)
	{
		printf ("test :%s \n", argv[i]);
		i++;
	}

	// i = 0;
	// fd = open("foo1.txt", O_RDONLY);
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	printf("%s",line);
	// 	if (line == NULL)
	// 	{	
	// 		free(line);
	// 		break ;
	// 	}
	// 	free(line);
	// 	i++;
	// }
	// close(fd);

	line = NULL;

	while ((line = get_next_line(0)))
	{
		printf("GNL %s", line);
		free(line);
	}

	return (0);
}
