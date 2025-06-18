/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apn_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:50:11 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/17 17:54:48 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hed_red.h"

int	apn_red(t_data *data, char **red)
{
	int neo;

	neo = -1;
	if (access(red[1], F_OK) == -1)
		neo = open(red[1], O_CREAT | O_WRONLY, 0644);
	else if (access(red[1], W_OK) == -1)
	{
		write(2, "Permission denied\n", 19);
		return 1;
	}
	else
		neo = open(red[1], O_APPEND | O_WRONLY);
	data->fd = neo;
	return 0;
}
