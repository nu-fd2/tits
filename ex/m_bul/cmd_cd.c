/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:47:13 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/25 17:56:38 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

char	*n_path(t_data *data, char *opeth)
{
	char *path;
	char *home;

	if (opeth[0] != '~')
	{
		path = my_strdup(opeth);
		return (path);
	}
	home = gky_env(data->env, "HOME");
	path = my_strjoin(home, &opeth[1]);
	return (path);
}

int cmd_cd(t_data *data, char **arg)
{
	t_env	*pwd;

	char (*tmp), (*pmt);
	if (!data || !data->env)
		return (1);
	if (!arg[0] || arg[0][0] == '\0')
	{
		pmt = getenv("HOME");
		tmp = my_strdup(pmt);
	}
	else
		tmp = n_path(data, arg[0]);
	pwd = grp_env(data->env, "PWD");
	if (!pwd)
	{
		printf("tmp 1: %s\n", tmp);
		return (free(tmp), 1);
	}
	if (chdir(tmp))
	{
		write(2, "Error: chdir: fin ghadi??\n", 26);
		return (free(tmp), 1);
	}
	add_env(data->env, "OLDPWD", pwd->value, 1);
	add_env(data->env, "PWD", tmp, 1);
	printf("tmp 2: %s\n", tmp);
	free(tmp);
	return (0);
}
