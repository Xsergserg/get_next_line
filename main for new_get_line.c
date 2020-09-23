/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main for new_get_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 12:56:47 by rbeach            #+#    #+#             */
/*   Updated: 2020/05/30 20:47:31 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		ret1;
	int		ret2;


	fd1 = open("tests/test1", O_RDONLY);
	fd2 = open("tests/test2", O_RDONLY);
	while ((ret1 = get_next_line(fd1, &line)) > 0)
	{
		printf("|%s|\n", line);
		free(line);
		get_next_line(fd2, &line);
		printf("|%s|\n", line);
		free(line);
	}
	printf("|%s\n", line);
	free(line);
	ret2 = get_next_line(fd2, &line);
	printf("|%s\n", line);
	free(line);
	printf("---------------------return(test1)=%d------------\n", ret1);
	printf("---------------------return(test2)=%d------------\n", ret2);
	close(fd1);
	close(fd2);
	fd1 = open("tests/test3", O_RDONLY);
	while ((ret1 = get_next_line(fd1, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
	}
	printf("|%s\n", line);
	printf("---------------------return(test3)=%d------------\n", ret1);
	free(line);
	close(fd1);
	return (1);
}
