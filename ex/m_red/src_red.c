/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:20:12 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/24 16:03:54 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Token_and_lex.h"


int	src_red(t_data *data, char **red)
{
	int	i;

	i = 0;
	if (!red || !red[0] || !red[1])
		return 1;
	else if (ft_strncmp(red[0], ">", 2) == 0)
		red_red(data, red[1]);
	else if (ft_strncmp(red[0], ">>", 3) == 0)
		apn_red(data, red[1]);
	else if (ft_strncmp(red[0], "<", 2) == 0)
		inn_red(data, red[1]);
	else if (ft_strncmp(red[0], "<<", 3) == 0)
		printf("dogs ahead\n");
	else
		printf("cum\n");
	return 0;
}
