#include "../cub3d.h"

void	clean_graphics(t_graphics *graphics)
{
	if (graphics->init && graphics->window)
		mlx_destroy_window(graphics->init, graphics->window);
	if (graphics->init)
		mlx_destroy_context(graphics->init);
	free(graphics);
}