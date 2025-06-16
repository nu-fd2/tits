/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:32:17 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/16 10:50:54 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hed_red.h"

int	red_red(t_data *data, char **red)
{
	int neo;

	neo = -1;
	if (access(red[1], F_OK) == -1)
	{
		neo = open(red[1], O_CREAT | O_WRONLY, 0644);
		write(2, "Can't open\n", 19);
		if (neo == -1)
			return 1;
	}
	else if (access(red[1], W_OK) == -1)
	{
		write(2, "Permission denied\n", 19);
		return 1;
	}
	else
	{
	}
	return 0;
}
