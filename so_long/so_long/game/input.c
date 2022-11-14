/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:55:05 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/14 10:04:36 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_action_animation(t_player *player)
{
	player->framecount = 0;
	player->current_img = player->action_img;
}

t_bool	ft_move(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		move_to_collectable(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game, tile);
	else if (tile->type == ENEMY || tile->type == FOLLOWER)
	{
		move_to_enemy(game, tile);
		return (FALSE);
	}
	else
		return (FALSE);
	move_enemy(game);
	return (TRUE);
}

int	ft_input(int key, t_game *game)
{
	t_bool	move;

	if (key == ESC)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		move = ft_move(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		move = ft_move(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		move = ft_move(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		move = ft_move(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		ft_printf("Moves: %d", ++game->moves);
	return (1);
}