/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:20:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/09 14:26:39 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (false);
		line++;
	}
	return (true);
}

int	find_map_start(char **file, int pos_map)
{
	int		i;

	i = pos_map + 1;
	while (file[i] && is_empty_line(file[i]))
		i++;
	return (i);
}

int	dir_player(char dir)
{
	if (dir == 'N')
		return (1);
	else if (dir == 'S')
		return (2);
	else if (dir == 'W')
		return (3);
	else if (dir == 'E')
		return (4);
	return (-1);
}

bool	get_ppos(t_cube *cube, int pos_map)
{
	int	i;
	int	j;
	int	pc;

	pc = 0;
	i = pos_map - 1;
	while (cube->file[++i])
	{
		j = -1;
		while (cube->file[i][++j])
		{
			if (cube->file[i][j] == 'N' || cube->file[i][j] == 'S' || cube->file[i][j] == 'W' || cube->file[i][j] == 'E')
			{
				pc++;
				cube->player_x = i - pos_map;
				cube->player_y = j;
				cube->pos = dir_player(cube->file[i][j]);
				printf("pc = %d\tplayer_x = %d\tplayer_y = %d\n", pc, i - pos_map, j);
			}
		}
	}
	if (pc == 1)
		return (true);
	return (false);
}

// Función DFS para verificar que el mapa esté cerrado
int is_closed_dfs(t_cube *cube, int i, int j, int **visited)
{
	// Verificar límites del mapa
	if (i < 0 || i >= cube->map_h || j < 0 || j >= cube->map_w)
		return 0; // Fuera de los límites (mapa abierto)
	if (cube->map[i][j] == '1')
		return 1; // Borde encontrado
	if (cube->map[i][j] == ' ' || visited[i][j])
		return 1; // Espacio o ya visitado

	visited[i][j] = 1; // Marcar celda como visitada

	// Recorrer las cuatro direcciones
	int up = is_closed_dfs(cube, i - 1, j, visited);
	int down = is_closed_dfs(cube, i + 1, j, visited);
	int left = is_closed_dfs(cube, i, j - 1, visited);
	int right = is_closed_dfs(cube, i, j + 1, visited);

	return up && down && left && right;
}

// Verificar que el mapa esté cerrado por '1's
int is_valid_map(t_cube *cube)
{
	int **visited = (int **)malloc(cube->map_h * sizeof(int *));
	for (int i = 0; i < cube->map_h; i++)
	{
		visited[i] = (int *)calloc(cube->map_w, sizeof(int));
	}

	int valid = 1;
	for (int i = 0; i < cube->map_h && valid; i++)
	{
		for (int j = 0; j < cube->map_w && valid; j++)
		{
			if (cube->map[i][j] != '1' && cube->map[i][j] != ' ' && !visited[i][j])
			{
				valid = is_closed_dfs(cube, i, j, visited);
				if (!valid)
					break;
			}
		}
	}

	// Liberar memoria
	for (int i = 0; i < cube->map_h; i++)
	{
		free(visited[i]);
	}
	free(visited);

	return valid;
}

void	invalid_map(t_cube *cube)
{
	free_all(cube);
	generic_exit("Invalid map.");
}

void	store_map(t_cube *cube, int pos_map)
{
	int	i;

	i = pos_map + cube->map_h - 1;
	while (i >= pos_map && is_empty_line(cube->file[i]))
	{
		cube->map_h--;
		i--;
	}
	cube->map = (char **)malloc(sizeof(char *) * cube->map_h);
	if (!cube->map)
		generic_exit("Memory allocation failed.");
	i = pos_map;
	while (i < pos_map + cube->map_h)
	{
		cube->map[i - pos_map] = ft_strdup(cube->file[i]);
		if (!cube->map[i - pos_map])
		{
			generic_exit("Memory allocation failed.");
		}
		i++;
	}
}

void	get_map_limits(t_cube *cube, int pos_map)
{
	int	i;
	int	j;

	i = pos_map;
	while (cube->file[++i])
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
	if (!is_valid_map(cube))
		invalid_map(cube);
	printf("valid map\n");
	// check_playable(cube);
	print_struct(cube);
}
