/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:20:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/14 10:14:01 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Función DFS para verificar que el mapa esté cerrado
int	is_closed_dfs(t_cube *cube, int i, int j, int **visited)
{
	int	up;
	int	down;
	int	left;
	int	right;

	// Verificar límites del mapa
	if (i < 0 || i >= cube->map_h || j < 0 || j >= ft_strlen(cube->map[i]))
		return (0); // Fuera de los límites (mapa abierto)
	if (cube->map[i][j] == '1')
		return (1); // Borde encontrado
	if (cube->map[i][j] == ' ' || visited[i][j])
		return (1); // Espacio o ya visitado
	// Marcar celda como visitada
	visited[i][j] = 1;

	// Recorrer las cuatro direcciones
	up = is_closed_dfs(cube, i - 1, j, visited);
	down = is_closed_dfs(cube, i + 1, j, visited);
	left = is_closed_dfs(cube, i, j - 1, visited);
	right = is_closed_dfs(cube, i, j + 1, visited);

	return (up && down && left && right);
}

// Verificar que el mapa esté cerrado por '1's
int	is_valid_map(t_cube *cube)
{
	int	**visited;
	int	valid;
	int	i;
	int	j;

	visited = (int **)malloc(cube->map_h * sizeof(int *));
	if (!visited)
		generic_exit("Memory allocation failed.");
	i = -1;
	while (++i < cube->map_h)
		visited[i] = (int *)malloc(cube->map_w * sizeof(int));
	valid = 1;
	i = -1;
	while (++i < cube->map_h && valid)
	{
		j = -1;
		while (++j < cube->map_w && valid)
		{
			if (cube->map[i][j] != '1' && cube->map[i][j] != ' '
				&& !visited[i][j])
			{
				valid = is_closed_dfs(cube, i, j, visited);
				if (!valid)
					break ;
			}
		}
	}
	// free_dp_int(visited); //???????
	return (valid);
}

void	store_map(t_cube *cube, int pos_map)
{
	int	i;
	int	j;

	j = 0;
	i = pos_map - 1;
	cube->map = malloc(sizeof(char *) * (cube->map_h + 1));
	if (!cube->map)
		generic_exit("Memory allocation failed."); //erro malloc
	while ((++i - pos_map) < cube->map_h)
	{
		// printf("str; %s\ti: %d\n", cube->file[i] ,i);
		j = -1;
		cube->map[i - pos_map] = malloc(sizeof(char) * (cube->map_w + 1));
		if (!cube->map[i - pos_map])
			generic_exit("Memory allocation failed."); //erro malloc
		while (++j < cube->map_w)
		{
			if (cube->file[i][j])
				cube->map[i - pos_map][j] = cube->file[i][j];
			else
				cube->map[i - pos_map][j] = ' ';
		}
		cube->map[i - pos_map][j] = '\0';
	}
	cube->map[i - pos_map] = NULL;
}

void	get_map_limits(t_cube *cube, int pos_map)
{
	int	i;
	int	j;

	i = pos_map;
	while (cube->file[++i] && is_empty_line(cube->file[i]) == false)
	{
		j = -1;
		while (cube->file[i][++j])
		{
			if (j > cube->map_w)
				cube->map_w = j;
		}
	}
	cube->map_h = i - pos_map;
}

void	map_parsing(t_cube *cube, int pos_map)
{
	pos_map = find_map_start(cube->file, pos_map);
	if (!get_ppos(cube, pos_map))
		generic_exit("Check player on map. Not found or more than one.");
	get_map_limits(cube, pos_map);
	store_map(cube, pos_map);
	// if (!is_valid_map(cube))
	// 	invalid_map(cube);
	// check_playable(cube);
	// print_struct(cube);
}
