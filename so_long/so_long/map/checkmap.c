/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:59:45 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/14 13:48:23 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.h"

int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (ft_error("Error\nNo Map Selected."));
	else if (argc > 2)
		(ft_print_warning("Warning!\nOnly 1st map 'll be used."));
	else if (!ft_strend_cmp(file, ".ber"))
		return (ft_error("Error\nMap's not a .ber file."));
	return (1);
}

static t_mapcheckerdata	init_checkerdata(char **map)
{
	t_mapcheckerdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chartable_linecount(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE;
	data.point.x = 0;
	data.point.y = 0;
	return (data);
}

static int	ft_checks(char **map, t_mapcheckerdata *data)
{
	int	x;
	int y;

	x = data->point.x;
	y = data->point.y;
	if (!ft_valid_char(map[x][y]))
		return (ft_error("Error\nInvalid Character."));
	else if (!ft_valid_uniquechar(map[x][y], 'P', &data->b_player))
		return (ft_error("Error\nOnly 1 character available."));
	else if (map[x][y] == 'E')
		data->b_exit = TRUE;
	else if (!ft_valid_border(map[x][y], data->point, data->size))
		return (ft_error("Error\nMap opened. Some wall are missing."));
	else if (map[x][y] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}

int	valid_map(char **map)
{
	t_mapcheckerdata	data;
	t_bool				valid;

	data = init_checkerdata(map);
	valid = TRUE;
	while (map[data.point.y])
	{
		if (ft_strlen(map[data.point.y] != data.size.x))
			valid = ft_error("Error\nMap's not rectangular");
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (ft_checks(map, &data) == FALSE)
				valid = FALSE;
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || !data.b_exit || !data.b_collect)
		valid = ft_error("Error\nMissing P or E or at least 1 C");
	return (valid);
}

