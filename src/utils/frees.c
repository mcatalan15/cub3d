/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:00:50 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/06/18 11:27:11 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	free_dp(char **dp)
{
	int	i;

	i = 0;
	while (dp[i])
	{
		free(dp[i]);
		i++;
	}
	free(dp);
	return (0);
}

int	free_dp_int(int **dp)
{
	int	i;

	i = 0;
	while (dp[i])
	{
		free(dp[i]);
		i++;
	}
	free(dp);
	return (0);
}

int	free_all(t_cube *cube)
{
	free_dp(cube->file);
	free_dp(cube->map);
	free(cube->n_text);
	free(cube->s_text);
	free(cube->e_text);
	free(cube->w_text);
	return (0);
}
