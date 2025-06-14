/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cpro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:56:16 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/14 17:09:42 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_exc.h"

int	ex_cpro(t_data *data, char *cmd, char **arg)
{
	int		sta;
	int		wife;
	int		wife2;
	pid_t	kid;

	sta = 0;
	kid = fork();
	if (kid < 0)
		return 1;
	if (kid == 0)
	{
		execv(cmd, arg);
		// execve(cmd, arg, char **env); USE TS
		return (1);
	}
	else
	{
        waitpid(kid, &sta, 0);
		wife = WIFEXITED(sta);
		wife2 = WEXITSTATUS(sta);
		if (wife)
			return (wife);
		else if (wife2)
			return (128 + wife2);
	}
	return (0);
}
