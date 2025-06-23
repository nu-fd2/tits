/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:32:17 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/22 22:42:32 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Token_and_lex.h"


int	red_red(t_data *data, char *red)
{
	int neo;

	neo = -1;
	if (access(red, F_OK) == -1)
		neo = open(red, O_CREAT | O_WRONLY, 0644);
	else if (access(red, W_OK) == -1)
	{
		write(2, "Permission denied\n", 19);
		return 1;
	}
	else
		neo = open(red, O_WRONLY);
	data->fd = neo;
	return 0;
}
