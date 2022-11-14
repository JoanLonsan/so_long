// Color transformation

#include "mlx_hiw.h"

t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

static void	turn_pixel_to_color(char *pixel, t_color color)
{
	pixel[0] = color.b;
	pixel[1] = color.g;
	pixel[2] = color.r;
	pixel[3] = color.a;
}

void	turn_img_to_color(t_image *image, t_color color)
{
	int	x;
	int	y;

	y = 0;
	while (y < image->size.y)
	{
		x = 0;
		while (x < image->size.x)
		{
			turn_pixel_to_color(
				&image->pixels[x + 4 + image->line_size * y], color);
			x++;
		}
		y++;
	}
}
