/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:34:31 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/14 14:03:27 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../includes/so_long.h"
# include "../core.h"

typedef struct s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}				t_mapcheckerdata;

int		valid_file(int argc, char *file);
int		valid_map(char **map);
void	add_enemy(t_game *game, t_enemyytpe type, t_tile *tile);
int		ft_valid_char(char c);
int		ft_valid_uniquechar(char c, char check, t_bool *bool);
int		ft_valid_border(char c, t_vector point, t_vector size);
char	**read_map(char *file);

#endif