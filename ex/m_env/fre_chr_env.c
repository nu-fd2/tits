/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fre_chr_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:04:24 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/14 22:35:18 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	fre_chr_env(t_data *data)
{
	char	**ts;
	int	i;

	i = 0;
	ts = data->chr_env;
	while(ts[i])
	{
		free(ts[i]);
		i++;
	}
	free(data->chr_env);
}
