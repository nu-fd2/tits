/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:17:57 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/25 17:57:15 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

char *key_gen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
	{
		if (!my_isalpha(arg[i]) && arg[i] != '_')
			return (NULL);
		i++;
	}
	return (my_strndup(arg, i));
}

char	*val_gen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
		i++;
	return (my_strdup(&arg[i + 1]));
}

int	prt_gen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	cmd_export(t_data *data, char **arg)
{
	int (i), (s), (ret);
	char (*key), (*val);
	i = 0;
	ret = 0;
	if (!data || !data->env)
		return (1);
	if (!arg || !arg[0])
		return (prn_port_env(data), 0);
	while (arg[i])
	{
		key = NULL;
		val = NULL;
		key = key_gen(arg[i]);
		if (!key)
			ret = 1;
		if (key && key[0] != '\0')
		{
			s = prt_gen(arg[i]);
			val = val_gen(arg[i]);
			add_env(data->env, key, val, s);
		}
		i++;
	}
	free(key);
	free(val);
	return (ret);
}
