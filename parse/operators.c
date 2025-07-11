/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:41:24 by mdakni            #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int handle_pipe(t_input **list, char *line)
{
	t_input *tmp;

	if(line[0] == '|')
	{
		ft_lstadd_back(list, my_strdup("|"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_PIPE;
		tmp->category = TOKEN_OP;
		return 1;
	}
	return 0;
}

int handle_red(t_input **list, char *line)
{
	t_input *tmp;

	if(line[0] == '>' && line[1] != '>')
	{
		ft_lstadd_back(list, my_strdup(">"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_R_RED;
		tmp->category = TOKEN_RED_APP;
		tmp->red_app = true;
		return 1;
	}
	else if(line[0] == '<' && line[1] != '<')
	{
		ft_lstadd_back(list, my_strdup("<"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_L_RED;
		tmp->category = TOKEN_RED_APP;
		tmp->red_app = true;
		return 1;
	}
	return 0;
}

int handle_app(t_input **list, char *line)
{
	t_input *tmp;

	if(line[0] == '>' && line[1] == '>')
	{
		ft_lstadd_back(list, my_strdup(">>"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_R_APP;
		tmp->category = TOKEN_RED_APP;
		tmp->red_app = true;
		return 2;
	}
	else if(line[0] == '<' && line[1] == '<')
	{
		ft_lstadd_back(list, my_strdup("<<"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_HEREDOC;
		tmp->category = TOKEN_RED_APP;
		tmp->red_app = true;
		return 2;
	}
	return 0;
}
