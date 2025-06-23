/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gky_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 08:38:32 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/19 17:28:19 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Token_and_lex.h"


char	*gky_env(t_env *env, char *key)
{
	t_env	*n_env;

	n_env = grp_env(env, key);
	return (n_env->value);
}
