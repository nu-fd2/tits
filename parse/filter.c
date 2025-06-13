/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:37:25 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/30 13:37:35 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void syntax_error(t_token type, t_input *list, t_input *iter)
{
    if(type == TOKEN_PIPE)
        printf("Syntax Error near unexpected Token '|' \n");
    if(type == TOKEN_R_RED || type == TOKEN_L_RED)
    {
        if(iter->next->value == NULL)
            printf("Syntax Error near unexpected Token 'newline' \n");
        else
            printf("Syntax Error near unexpected Token '%s' \n", iter->next->value);
    }
    else if(type == TOKEN_R_APP || type == TOKEN_L_APP)
    {
        if(iter->next->value == NULL)
            printf("Syntax Error near unexpected Token 'newline' \n");
        else
            printf("Syntax Error near unexpected Token '%s' \n", iter->next->value);
    }
    ft_lstfree(list);
}

// this function manages the first level of syntax checking (words, operators, delimiters)
void filter(t_input *list)
{
    t_input *iter;

    iter = list;
    while(iter)
    {
        if(iter->type == TOKEN_PIPE && iter->next->type == TOKEN_PIPE)
            return(syntax_error(TOKEN_PIPE, list, iter));
        if((iter->type == TOKEN_R_RED || iter->type == TOKEN_L_RED) && !(iter->next->value))
            return(printf("3 : %d\n", iter->index) ,syntax_error(iter->type, list, iter));
        if((iter->type == TOKEN_R_APP || iter->type == TOKEN_L_APP) && !(iter->next->value))
            return(printf("4 : %d\n", iter->index) ,syntax_error(iter->type, list, iter));
        if(iter->type == TOKEN_PIPE && (!(iter->prev) || !(iter->next->value)))
            return(printf("1 : %d\n", iter->index) ,syntax_error(iter->type, list, iter));
        if(iter->category == TOKEN_RED_APP && iter->next->category != TOKEN_WORD)
            return(printf("5 : %d\n", iter->index) ,syntax_error(iter->type, list, iter));
        iter = iter->next;
    }
    if(list->quotes != 0)
    {
        if(list->quotes == 1)
            printf("Open Single Quote Error\n");
        if(list->quotes == 2)
            printf("Open Double Quote Error\n");
        return(ft_lstfree(list));
    }
}
