/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:13:29 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/10 10:28:22 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int	is_playable(t_cube *cube, int x, int y)
{
	if (cube->map[x][y] == '1' || cube->map[x][y] == ' ')
		return (0);
	return (1);
}

int	is_border_space(t_cube *cube, int x, int y)
{
	if (x == 0 || x == cube->map_h - 1 || y == 0 || y == cube->map_w - 1)
		return (1);
	if (cube->map[x - 1][y] == ' ' || cube->map[x + 1][y] == ' ' ||
		cube->map[x][y - 1] == ' ' || cube->map[x][y + 1] == ' ' ||
		cube->map[x - 1][y - 1] == ' ' || cube->map[x - 1][y + 1] == ' ' ||
		cube->map[x + 1][y - 1] == ' ' || cube->map[x + 1][y + 1] == ' ')
	{
		generic_exit("Spaces in playable area.");
		return (1);
	}
	return (0);
}

int	diagonal(t_cube *cube, int x, int y, char **visited)
{
	if (is_playable(cube, x - 1, y - 1)
		&& !recursive(cube, x - 1, y - 1, visited))
		return (0);
	if (is_playable(cube, x - 1, y + 1)
		&& !recursive(cube, x - 1, y + 1, visited))
		return (0);
	if (is_playable(cube, x + 1, y - 1)
		&& !recursive(cube, x + 1, y - 1, visited))
		return (0);
	if (is_playable(cube, x + 1, y + 1)
		&& !recursive(cube, x + 1, y + 1, visited))
		return (0);
	return (1);
}

int	recursive(t_cube *cube, int x, int y, char **visited)
{
	if (visited[x][y])
		return (1);
	if (is_border_space(cube, x, y))
		return (0);
	visited[x][y] = 1;
	if (is_playable(cube, x - 1, y) && !recursive(cube, x - 1, y, visited))
		return (0);
	if (is_playable(cube, x + 1, y) && !recursive(cube, x + 1, y, visited))
		return (0);
	if (is_playable(cube, x, y + 1) && !recursive(cube, x, y + 1, visited))
		return (0);
	if (is_playable(cube, x, y - 1) && !recursive(cube, x, y - 1, visited))
		return (0);
	if (diagonal(cube, x, y, visited) == 0)
		return (0);
	return (1);
}

bool	is_valid_map(t_cube *cube)
{
	int		i;
	char	**visited;
	int		res;

	i = 0;
	visited = malloc(sizeof(char *) * cube->map_h);
	if (!visited)
		malloc_err(1);
	while (i < cube->map_h)
	{
		visited[i] = malloc(sizeof(char) * cube->map_w);
		if (!visited[i])
			malloc_err(1);
		i++;
	}
	res = recursive(cube, cube->player_x, cube->player_y, visited);
	i = 0;
	while (i < cube->map_h)
		free(visited[i++]);
	free(visited);
	if (res == 0)
		return (false);
	return (true);
}
