// Window management

#include "mlx_hiw.h"
#include <stdlib.h>

static int	ft_close(void)
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int width, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, width, height, name);
	window.size.x = width;
	window.size.y = height;
	/* Event "17" = DestroyNotify (or Window Closed). 
	List of events: https://harm-smits.github.io/42docs/libs/minilibx/events.html*/
	mlx_hook(window.reference, 17, 0, ft_close, 0);
	return (window);
}
