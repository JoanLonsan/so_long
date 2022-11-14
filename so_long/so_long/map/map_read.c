/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:37:49 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/14 11:56:44 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.h"
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

static int	ft_linecount(char *file)
{
	int		count;
	int		fd;
	int		readcount;
	char	a;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	count = 1;
	while (TRUE)
	{
		readcount = read(fd, &a, 1);
		if (readcount == 0)
			break ;
		else if (readcount < 0)
			return (-1);
		else if (a == '\n')
			count++;
	}
	close(fd);
	return (count);
}

static char	**ft_alloc_col(char *file)
{
	char	**map;
	int		count;

	count = ft_linecount(file);
	if (count <= 0)
		return (ft_null_error("Error\nOpen or Read error"));
	map = malloc(sizeof(char *) * count + 1);
	if (!map)
		return (ft_null_error("Error\nMalloc"));
	return (map);
}

char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = ft_alloc_col(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (ft_get_next_line(fd, &map[i]))
		i++;
	map[i] = NULL;
	close (fd);
	return (map);
}
