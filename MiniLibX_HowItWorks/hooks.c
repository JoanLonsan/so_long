// Ft for mlx_hook management.

#include "mlx_hiw.h"
#include <stdio.h>

int	ft_input(int key, void *param)
{
	t_program	*program = (t_program *)param;

	mlx_clear_window(program->mlx, program->window.reference);

	if (key == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)
		program->sprite_position.y -= program->sprite.size.y;
	else if (key == 15)
		turn_img_to_color(&program->sprite, new_color(255, 0, 0, 0));
	else if (key == 5)
		turn_img_to_color(&program->sprite, new_color(0, 255, 0, 0));
	else if (key == 11)
		turn_img_to_color(&program->sprite, new_color(0, 0, 255, 0));
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x,
		program->sprite_position.y);
	printf("Key pressed = %d\n", key);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program = (t_program *)param;
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x,
		program->sprite_position.y);
	return (0);
}
