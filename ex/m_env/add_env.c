/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:50:36 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/25 17:56:07 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*add_env(t_env *env, char *key, char *value, bool ported)
{
	t_env (*nu_env), (*tm_env);
	if (!key || key[0] == '\0')
		return (NULL);
	tm_env = grp_env(env, key);
	if (!tm_env)
	{
		tm_env = env;
		while (tm_env->next)
			tm_env = tm_env->next;
		nu_env = my_calloc(sizeof(t_env), 1);
		nu_env->key = my_strdup(key);
		if (value)
			nu_env->value = my_strdup(value);
		else
			nu_env->value = NULL;
		nu_env->ported = ported;
		nu_env->next = NULL;
		tm_env->next = nu_env;
		return (nu_env);
	}
	if (ported == 0)
		return (tm_env);
	free(tm_env->value);
	tm_env->value = my_strdup(value);
	tm_env->ported = 1;
	return(tm_env);
}
