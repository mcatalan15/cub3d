/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:20:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/17 17:27:14 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// // Función DFS para verificar que el mapa esté cerrado
// int	is_closed_dfs(t_cube *cube, int i, int j, int **visited)
// {
// 	int	up;
// 	int	down;
// 	int	left;
// 	int	right;
// 	int	row_len;

// 	// Verificar límites del mapa
// 	if (i < 0 || i >= cube->map_h || j < 0 || j >= (row_len = ft_strlen(cube->map[i])))
// 		return (0); // Fuera de los límites (mapa abierto)
// 	if (cube->map[i][j] == '1')
// 		return (1); // Borde encontrado
// 	if (cube->map[i][j] == ' ' || visited[i][j])
// 		return (1); // Espacio o ya visitado
// 	// Marcar celda como visitada
// 	visited[i][j] = 1;

// 	// Recorrer las cuatro direcciones
// 	up = is_closed_dfs(cube, i - 1, j, visited);
// 	down = is_closed_dfs(cube, i + 1, j, visited);
// 	left = is_closed_dfs(cube, i, j - 1, visited);
// 	right = is_closed_dfs(cube, i, j + 1, visited);

// 	return (up && down && left && right);
// }

// // Verificar que el mapa esté cerrado por '1's
// int	is_valid_map(t_cube *cube)
// {
// 	int	**visited;
// 	int	valid;
// 	int	i;
// 	int	j;

// 	visited = (int **)malloc(cube->map_h * sizeof(int *));
// 	if (!visited)
// 		generic_exit("Memory allocation failed.");
// 	i = -1;
// 	while (++i < cube->map_h)
// 	{
// 		visited[i] = (int *)malloc(ft_strlen(cube->map[i]) * sizeof(int));
// 		if (!visited[i])
// 			generic_exit("Memory allocation failed.");
// 	}
// 	valid = 1;
// 	i = -1;
// 	while (++i < cube->map_h && valid)
// 	{
// 		j = -1;
// 		while (++j < ft_strlen(cube->map[i]) && valid)
// 		{
// 			if (cube->map[i][j] != '1' && cube->map[i][j] != ' ' && !visited[i][j])
// 			{
// 				valid = is_closed_dfs(cube, i, j, visited);
// 				if (!valid)
// 					break ;
// 			}
// 		}
// 	}
// 	// Liberar memoria de la matriz visited
// 	i = -1;
// 	while (++i < cube->map_h)
// 		free(visited[i]);
// 	free(visited);

// 	return (valid);
// }

// // Function to check if the map is enclosed by '1's
// bool is_valid(char **map, int height) {
//     // Check the top border
//     for (int j = 0; map[0][j] != '\0'; ++j) {
//         if (map[0][j] != '1' && map[0][j] != ' ') {
//             printf("Top border check failed at column %d\n", j);
//             return false;
//         }
//     }

//     // Check the bottom border
//     for (int j = 0; map[height - 1][j] != '\0'; ++j) {
//         if (map[height - 1][j] != '1' && map[height - 1][j] != ' ') {
//             printf("Bottom border check failed at column %d\n", j);
//             return false;
//         }
//     }

//     // Check the left and right borders for each row
//     for (int i = 0; i < height; ++i) {
//         int len = strlen(map[i]);
//         if (map[i][0] != '1' && map[i][0] != ' ') {
//             printf("Left border check failed at row %d\n", i);
//             return false;
//         }
//         if (map[i][len - 1] != '1' && map[i][len - 1] != ' ') {
//             printf("Right border check failed at row %d, length %d\n", i, len);
//             return false;
//         }
//     }

//     return true;
// }

void	store_map(t_cube *cube, int pos_map)
{
	int	i;

	i = -1;
	cube->map = malloc(sizeof(char *) * (cube->map_h + 1));
	if (!cube->map)
		generic_exit("Error malloc"); //erro malloc
	while (++i < cube->map_h)
	{
		cube->map[i] = ft_strdup(cube->file[i + pos_map]);
		if (!cube->map[i])
		{
			free(cube->map);
			generic_exit("Error malloc"); //error malloc		
		}
	}
	
	cube->map[i] = NULL;
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

bool	check_ones(char *str)
{
	int	i;
	int flag;

	flag = 0;
	i = -1;
	printf("str: %s\n", str);
	while (str[++i])
	{
		if (str[i] != '1' && ft_isspace(str[i]) == 0)
			flag = 1;
	}
	if (flag == 1)
		return (false);
	return (true);
}

int	checker_0(t_cube *cube, int i, int j)
{

	printf("i: %d\t j: %d\n", i ,j);
	if (cube->map[i][j + 1] == ' ')
		return (1);
	else if (cube->map[i][j - 1] == ' ')
		return (1);
	else if (cube->map[i + 1][j] == ' ')
		return (1);
	else if (cube->map[i - 1][j] == ' ')
		return (1);
	else if (j == (cube->map_w - 1) || j == 0)
		return (1);
	// printf("%s", cube->map[i]);
	return (0);
}

bool	is_valid_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("map_w: %d\n", cube->map_w);
	if (!check_ones(cube->map[0]) || !check_ones(cube->map[cube->map_h - 1]))
		generic_exit("Error map");
	printf(GREEN"first and last line OK\n"RST);
	while (++i < (cube->map_h - 1))
	{
		printf("%s", cube->map[i]);
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == '0')
			{
				if (checker_0(cube, i, j) == 1)
					generic_exit("map invalid");
				j++;
			}
			else
				j++;
		}
	}
	printf("iepiep\n");
	return (true);
}

void	map_parsing(t_cube *cube, int pos_map)
{
	pos_map = find_map_start(cube->file, pos_map);
	if (!get_ppos(cube, pos_map))
		generic_exit("Check player on map. Not found or more than one.");
	get_map_limits(cube, pos_map);
	store_map(cube, pos_map);
	print_dp(cube->map);
	if (!is_valid_map(cube))
		invalid_map(cube);
	printf("GOODMAP\n");
	// check_playable(cube);
	// print_struct(cube);
}
