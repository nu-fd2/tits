/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prn_port_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/19 17:28:55 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Token_and_lex.h"


// int	ma_strcmp(const char *s1, const char *s2)
// {
// 	size_t			i;
// 	unsigned char	*p1;
// 	unsigned char	*p2;

// 	i = 0;
// 	if (s1 == NULL || s2 == NULL)
// 	{
// 		if (s1 == NULL && s2 == NULL)
// 			return (0);
// 		else if (s1 == NULL)
// 			return (-1);
// 		else
// 			return (1);
// 	}
// 	p1 = (unsigned char *)s1;
// 	p2 = (unsigned char *)s2;
// 	while ((p1[i] || p2[i]))
// 	{
// 		if (p1[i] != p2[i])
// 			return (p1[i] - p2[i]);
// 		i++;
// 	}
// 	return (0);
// }

t_env	*cpy_env(t_env *env)
{
	int i;

	i = 0;
	t_env (*hd_env), (*nu_env), (*tm_env), (*og_env);
	nu_env = NULL;
	if (!env || !env->key)
		return (NULL);
	og_env = env;
	while(og_env)
	{
		nu_env = ft_calloc(sizeof(t_env), 1);
		nu_env->key = ft_strdup(og_env->key);
		nu_env->value = ft_strdup(og_env->value);
		nu_env->ported = og_env->ported;
		nu_env->next = NULL;
		if (i == 0)
			hd_env = nu_env;
		else
			tm_env->next = nu_env;
		i = 1;
		tm_env = nu_env;
		og_env = og_env->next;
	}
	return (hd_env);
}

void	swp_env(t_env *a, t_env *b)
{
	char	*tmp;
	int		port;

	port = 0;
	tmp = a->key;
	a->key = b->key;
	b->key = tmp;
	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
	port = a->ported;
	a->ported = b->ported;
	b->ported = port;
}

t_env	*srt_env(t_env *env)
{
	t_env	*n_env;
	t_env	*c_env;
	int		s;

	n_env = cpy_env(env);
	if (!n_env)
		return (NULL);
	s = 0;
	while (!s)
	{
		s = 1;
		c_env = n_env;
		while (c_env && c_env->next)
		{
			if (c_env->next->key && (ft_strcmp(c_env->key, c_env->next->key) > 0))
			{
				swp_env(c_env, c_env->next);
				s = 0;
			}
			c_env = c_env->next;
		}
	}
	return (n_env);
}

int	prn_port_env(t_data *data)
{
	t_env	(*h_env), (*n_env);

	h_env = srt_env(data->env);
	n_env = h_env;
	if (n_env == NULL)
	{
		write(2, "Error: prn_port_env\n", 20);
		return (1);
	}
	else
	{
		while (n_env != NULL)
		{
			ft_putstr_fd("declare -x ", data->fd);
			ft_putstr_fd(n_env->key, data->fd);
			if (n_env->ported == 1)
			{
				ft_putstr_fd("=\"", data->fd);
				ft_putstr_fd(n_env->value, data->fd);
				ft_putstr_fd("\"", data->fd);
			}
			ft_putstr_fd("\n", data->fd);
			n_env = n_env->next;
		}
		fre_env(h_env);
	}
	return (0);
}
