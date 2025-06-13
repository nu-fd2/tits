/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:35:13 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/30 14:37:32 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

int calculate_size_blyat(char *niggers)
{
    int i;
    int dick_size;
    int quote_flag;

    i = 0;
    dick_size = 0;
    quote_flag = 0;
    while(niggers[i])
    {
        quote_flag = ft_checker(niggers[i], quote_flag);
        if((niggers[i] == '"' && quote_flag != 1) || (niggers[i] == '\'' && quote_flag != 2))
        {
            i++;
            continue;
        }
        dick_size++;
        i++;
    }
    // printf(" size is : %d\n", dick_size);
    return(dick_size + 1);
}

char *tmp_assignment(t_input *list, int size)
{
    int i;
    int j;
    char *tmp;
    int quote_flag;

    i = 0;
    j = 0;
    tmp = NULL;
    quote_flag = 0;
    tmp = ft_calloc(size, 1);
    if(tmp == NULL)
        return NULL;
    while(list->value[i])
    {
        quote_flag = ft_checker(list->value[i], quote_flag);
        if((list->value[i] == '"'  && quote_flag != 1) || (list->value[i] == '\'' && quote_flag != 2))
        {
            i++;
            continue;
        }
        tmp[j++] = list->value[i++];
    }
    tmp[j] = '\0';
    return tmp;
}

void striper(t_input *list)
{
    char *tmp;
    int size;

    while(list->value)
    {
        size = calculate_size_blyat(list->value);
        if(size == 0)
        {
            list = list->next;
           continue;
        }
        tmp = tmp_assignment(list, size + 1);
        free(list->value);
        list->value = tmp;
        list = list->next;
    }
}
