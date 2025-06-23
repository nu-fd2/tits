/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:17:29 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/19 17:27:42 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Token_and_lex.h"

int	cmd_env(t_data *data)
{
	if (!data || !(data->env))
	{
		write(2, "Error: env is NULL\n", 19);
		return (1);
	}
	prn_env(data);
	return (0);
}
