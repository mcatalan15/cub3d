/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:21:48 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/28 10:36:31 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	malloc_err(int num)
{
	printf(RED"Error:\n\tMalloc failed\n"RST);
	exit(num);
}

void	generic_exit(char *str)
{
	printf(RED"Error:\n\t%s\n"RST, str);
	exit(1);
}
