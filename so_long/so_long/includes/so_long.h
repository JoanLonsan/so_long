/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:55:18 by jcrescen          #+#    #+#             */
/*   Updated: 2022/11/14 11:54:55 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../core.h"
# include <mlx.h>
# define IMG_SIZE 64

typedef enum e_tilekin
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_tilekin;

typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_wallimg
{
	void	*block;
	void	*ulcorner;
	void	*up;
	void	*urcorner;
	void	*right;
	void	*drcorner;
	void	*down;
	void	*dlcorner;
	void	*left;
}	t_wallimg;

typedef struct s_collimg
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_collimg;

typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_panel;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef enum e_enemykin
{
	HORIZONTAL_ENEM = 'H',
	VERTICAL_ENEM = 'V',
	FOLLOW_ENEM = 'F'
}	t_enemykin;

typedef struct s_enemyimgs
{
	int		basic_animation;
	void	*basic;
	void	*basic_01;
	void	*basic_02;
	int		follower_animation;
	void	*follow;
	void	*follow_01;
	void	*follow_02;
}	t_enemyimg;

typedef struct s_enemy
{
	t_enemyytpe			type;
	int					dir;
	t_tile				*og_tile;
	t_tile				*tile;
	struct s_enemy		*next;
}	t_enemy;

enum e_key
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53,
	RESET = 15
};

typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_enemy			*enemy_list;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_enemy_img		enemy_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
	void			*red_panel;
	void			*white_panel;
}	t_game;

t_bool	ft_start(t_game *game, int argc, char **argv);
t_color	ft_new_color(int r, int g, int b, int a);
void	*ft_new_panel(t_game *game, t_color color);
int		ft_input(int key, t_game *game);
int		ft_update(t_game *game);
void	ft_render(t_game game);
void	ft_effect_anim(t_effect *effect, t_vector pos);
void	ft_action_anim(t_player *player);
void	ft_remove_player(t_game *game);
void	ft_wasted(t_game *game, t_vector pos);
int		ft_reset(t_game *game);
int		ft_end_program(t_game *game);

#endif
