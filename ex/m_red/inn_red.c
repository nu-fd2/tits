/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inn_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:25:17 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/18 10:28:52 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hed_red.h"

int	inn_red(t_data *data, char **red)
{
	int neo;

	neo = -1;
	if (access(red[1], F_OK) == -1)
		write(2, "makaynx\n", 9);
	else if (access(red[1], R_OK) == -1)
	{
		write(2, "Permission denied\n", 19);
		return 1;
	}
	else
		neo = open(red[1], O_RDONLY);
	data->fd2 = neo;
	return 0;
}
