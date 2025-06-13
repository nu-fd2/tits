/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:13:20 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/28 22:13:44 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void handle_file(t_input *list)
{
    while(list)
    {
        if(list->red_app)
            list->next->type = TOKEN_FILE;
        list = list->next;
    }
}
void handle_cmd(t_input *list)
{
    bool check;

    check = false;
    while(list)
    {
        if(list->type == TOKEN_WORD && !check)
        {
            list->type = TOKEN_CMD;
            check = true;
        }
        if(list->type == TOKEN_PIPE)
            check = false;
        list = list->next;
    }
}

void handle_arg(t_input *list)
{
    while(list)
    {
        if(list->type == TOKEN_WORD)
            list->type = TOKEN_ARG;
        list = list->next;
    }
}

void handle_clear(t_input *list, t_blah *blah)
{
    t_input *tmp;

    tmp = list;
    while(tmp && tmp->value)
    {
        if(tmp->type == TOKEN_ARG || tmp->type == TOKEN_CMD)
            tmp->type = TOKEN_WORD;
        if(tmp->type == TOKEN_FILE && !blah->ambiguous)
            tmp->type = TOKEN_WORD;
        tmp = tmp->next;
    }
}

void seperator(t_input *list)
{
    handle_file(list);
    handle_cmd(list);
    handle_arg(list);
}
