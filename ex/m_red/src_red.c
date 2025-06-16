/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:20:12 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/16 07:30:33 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hed_red.h"

int	src_red(t_data *data, char **red)
{
	int	i;

	i = 0;
	if (ft_strncmp(red[0], ">", 2) == 0)
		red_red(data, red);
	// else if (ft_strncmp(red[0], ">>", 3) == 0)
	// else if (ft_strncmp(red[0], "<", 2) == 0)
	else if (ft_strncmp(red[0], "<<", 3) == 0)
		printf("dogs ahead");
}
