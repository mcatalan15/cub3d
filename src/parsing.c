/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:26 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/07 12:29:20 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	checker_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".cub", 4))
	{
		printf(RED "Error:\nInvalid file.\tNeeds .cub file\n" RST);
		return (1);
	}
	return (0);
}

int	parsing(t_cube *cube)
{
	(void)cube;
	printf("parsing\n");
	return (0);
}
