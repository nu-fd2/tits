/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_lst_creater.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:35:00 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/30 14:44:48 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

t_blah check_ambiguous(t_input *lst, t_blah blah)
{
    if(lst->type == TOKEN_FILE && lst->next)
    {
        if(lst->next->type == TOKEN_FILE)
            blah.ambiguous = true;
        }
        return blah;
}

void check_token_sizes(t_input *lst, t_blah *blah)
{
    while(lst && lst->value)
    {
        if(lst->value && lst->value[0] == '\0')
        {
            lst = lst->next;
            continue;
        }
        if(lst->red_app == true)
            blah->reds++;
        if(lst->type == TOKEN_FILE)
            blah->reds++;
        if(lst->type == TOKEN_ARG)
            blah->args++;
        if(lst->type == TOKEN_CMD)
            blah->args++;
        lst = lst->next;
    }
    // printf("args = %d, reds = %d\n", blah->args, blah->reds);
}

void assign_strings(t_blah *blah, t_input *lst)
{
    blah->args_i = 0;
    blah->reds_i = 0;
    while(lst && lst->value)
    {
        // printf("lst->value : %s\n", lst->value);
        if(lst->type == TOKEN_CMD && blah->args2 != NULL)
            blah->args2[blah->args_i++] = ft_strdup(lst->value);
        else if(lst->type == TOKEN_ARG && blah->args2 != NULL)
            blah->args2[blah->args_i++] = ft_strdup(lst->value);
        else if(lst->red_app == true && blah->reds2 != NULL)
            blah->reds2[blah->reds_i++] = ft_strdup(lst->value);
        else if(lst->type == TOKEN_FILE && blah->reds2 != NULL)
            blah->reds2[blah->reds_i++] = ft_strdup(lst->value);
        lst = lst->next;
    }
    if(blah->args2)
        blah->args2[blah->args_i] = NULL;
    if(blah->reds2)
        blah->reds2[blah->reds_i] = NULL;
}

void create_node(t_blah *blah, t_input *head)
{
    // while(lst->prev)
    //     lst = lst->prev;
    handle_clear(head, blah);
    // lst_print(head);
    seperator(head);
    check_token_sizes(head, blah);
    if(blah->args)
        blah->args2 = ft_calloc(blah->args + 1, sizeof(char *));
    else
        blah->args2 = NULL;
    if(blah->reds)
        blah->reds2 = ft_calloc(blah->reds + 1, sizeof(char *));
    else
        blah->reds2 = NULL;
    assign_strings(blah, head);
}

t_short *last_lst_creater(t_input *lst)
{
    t_blah blah;
    t_input *head;
    t_input *tail;
    t_short *new_lst;

    new_lst = NULL;
    while(lst)
    {
        blah.ambiguous = false;
        blah.args = 0;
        blah.reds = 0;
        head = lst;
        while(lst->value && lst->type != TOKEN_PIPE)
        {
            blah = check_ambiguous(lst, blah);
            lst = lst->next;
        }
        tail = lst->next;
        lst->next = NULL;
        create_node(&blah, head);
        ft_lstadd_back_2(&new_lst, blah);
        lst->next = tail;
        lst = tail;
    }
    return new_lst;
}

// find a way to free all cut lsts