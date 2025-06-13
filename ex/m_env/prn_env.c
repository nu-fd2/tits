/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prn_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/01 11:48:19 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	prn_env(t_data *data)
{
	t_env	*n_env;

	n_env = data->env;
	if (!data || !n_env)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (n_env != NULL)
	{
		if (n_env->ported == 1)
		{
			ft_putstr_fd(n_env->key, data->fd);
			ft_putstr_fd("=", data->fd);
			if (n_env->value)
				ft_putstr_fd(n_env->value, data->fd);
			ft_putstr_fd("\n", data->fd);
		}
		n_env = n_env->next;
	}
	return (0);
}
