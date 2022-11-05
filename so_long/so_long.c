/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:21:02 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/05 16:33:46 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map"/map.h"
#include "core.h"

int	main(void)
{
	t_game	game;

	if (!start(&game, argc, argv))
		return (0);
	mlx_hook(game.window.reference, *ft_input, &game);
	mlx_loop_hook(game.mlx, *ft_update, &program);
	mlx_loop(game.mlx);
	return (0);
}
