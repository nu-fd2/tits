/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:54:01 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/19 17:28:23 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Token_and_lex.h"


t_env	*grp_env(t_env *env, char *key)
{
	t_env	*tm_env;
	int		l;

	if (key == NULL || env == NULL)
		return (NULL);
	tm_env = env;
	l = ft_strlen(key);
	while (tm_env != NULL)
	{
		if (tm_env->key[l] == '\0' && ft_strncmp(tm_env->key, key, l) == 0)
			return (tm_env);
		tm_env = tm_env->next;
	}
	return (NULL);
}
