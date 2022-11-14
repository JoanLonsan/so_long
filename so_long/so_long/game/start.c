/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:17:13 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/14 09:45:08 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"

static t_tile	**ft_map_init(t_game *game, int argc, char **argv)
{
	char	**map;
	t_tile	**tile;

	if (!valid_file(argc, argv[1]))
		return (NULL);
	map = read_map(argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_map(map);
		return (NULL);
	}
	tile = generate_tile(map, game);
	ft_free_map(map);
	if (!tile)
		return (NULL);
	return (tile);
}

static void	ft_animation_setup(t_game *game)
{
	game->player.idle_frames = 17;
	game->player.action_frames = 10;
	game->collects_imgs.anim_frames = 25;
	game->effects.frames = 7;
	game->enemy_imgs.basic_animation = 16;
	game->enemy_imgs.follow_animation = 6;
}

static void	ft_game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->window_size.x + IMG_SIZE / 2,
			game->window_size.y, "so_long");
	mlx_hook(game->window, 17, 0, end_program. game);
	open_images(game);
	game->white_panel = new_panel(game, new_color(254, 254, 254, 0));
	game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
}

t_bool	start(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = ft_map_init(game, argc, argv);
	if (game->tilemap == NULL)
		return (FALSE);
	game->og_collects = game->collects;
	ft_animation_setup(game);
	ft_game_init(game);
	return (TRUE);
}
