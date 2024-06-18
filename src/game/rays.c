#include "../../includes/cub3d.h"

void	one_ray(t_mlx_data *data, t_cube *cube, t_vec raydir)
{

}

void	create_rays(t_mlx_data *data, t_cube *cube)
{
	int	i;
	double	camerax;
	t_vec	raydir;

	i = -1;
	data->p.map.x = (data->p.pos.x - 100) / BLOCK;
	data->p.map.y = (data->p.pos.y - 100) / BLOCK;
	while (++i < WIDTH)
	{
		camerax = 2 * i / (double)WIDTH - 1;
		raydir.x = data->p.dir.x + data->p.plane.x * camerax;
		raydir.y = data->p.dir.y + data->p.plane.y * camerax;
	}
}
