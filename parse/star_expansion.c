/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:41:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/29 19:08:17 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

bool wildcard_match(char *pattern, char *str)
{
    if(*pattern == '\0' && *str == '\0')
        return true;
    if(*pattern == '\0')
        return false;
    if(*pattern == '*')
        return wildcard_match(pattern + 1, str) || (*str != '\0' && wildcard_match(pattern, str + 1));
    if(*str == '\0')
        return false;
    if(*pattern == *str)
        return wildcard_match(pattern + 1, str + 1);
    return false;
}

void alpha_sort(t_input *iter)
{
    t_input *iter2;
    char *tmp;

    while(iter)
    {
        iter2 = iter->next;
        while(iter2)
        {
            if(ft_strcmp(iter->value, iter2->value))
            {
                tmp = iter->value;
                iter->value = iter2->value;
                iter2->value = tmp;
                break;
            }
            iter2 = iter2->next;
        }
            iter = iter->next;
    }
}

void ft_replace(t_input *add, t_input **iter, t_input **list)
{
    t_input *last;

    alpha_sort(add);
    last = ft_lstlast(add);
    // printf("add : ");
    // lst_print(add);
    // printf("\nlast : ");
    // lst_print(last);
    if((*iter)->prev)
        (*iter)->prev->next = add;
    else
        *list = add;
    if((*iter)->next)
        (*iter)->next->prev = last;
    last->next = (*iter)->next;
    (*iter)->next = NULL;
    ft_lstfree(*iter);
    (*iter) = last;
}

void add_and_assign_token(t_input **iter, struct dirent *read, t_input **add)
{
    t_input *last;

    if(wildcard_match((*iter)->value, read->d_name))
    {
        ft_lstadd_back(add, ft_strdup(read->d_name));
        last = ft_lstlast(*add);
        last->type = (*iter)->type;
    }
}

void read_and_create(t_input **iter, int q_flag, int s_flag, t_input **list)
{
    DIR *dir;
    struct dirent *read;
    t_input *add;

    (void)q_flag;
    // (void)list;
    add = NULL;
    dir = opendir(".");
    read = readdir(dir);
    while(read)
    {
        if(read->d_name[0] == '.' || (s_flag && read->d_type != DT_DIR))
        {
            read = readdir(dir);
            continue;
        }
        add_and_assign_token(iter, read, &add);
        // if(wildcard_match((*iter)->value, read->d_name))
        //     ft_lstadd_back(&add, ft_strdup(read->d_name));
        read = readdir(dir);
    }
    if(add)
        ft_replace(add, iter, list);
    closedir(dir);
}

            // printf("%s\n", read->d_name);
int ft_checker(char c, int quote_flag)
{
    if(c == '"' && quote_flag != 1)
    {
        if(quote_flag == 2)
            quote_flag = 0;
        else
            quote_flag = 2;
    }
    else if(c == '\'' && quote_flag != 2)
    {
        if(quote_flag == 1)
            quote_flag = 0;
        else
            quote_flag = 1;
    }
    return quote_flag;
}
void create_and_replace(t_input **iter, t_input **list)
{
    int i;
    int quote_flag;
    int star_flag;
    int slash_flag;

    i = 0;
    quote_flag = 0;
    star_flag = 0;
    slash_flag = 0;
    if((*iter)->value[i] == '.')
        return;
    while((*iter)->value[i])
    {
        quote_flag = ft_checker((*iter)->value[i], quote_flag);
        if((*iter)->value[i] == '*' && quote_flag == 0)
            star_flag = 1;
        else if((*iter)->value[i] == '/' && (*iter)->value[i + 1] == '\0')
            slash_flag = 1;
        i++;
    }
    if(star_flag == 1)
        read_and_create(iter, quote_flag, slash_flag, list);
}

t_input *star_expansion(t_input *list)
{
    t_input *tmp;

    tmp = list;
    while(tmp->value)
    {
        // printf("\nbefore iter : %s\n", tmp->value);
        // lst_print(tmp);
        create_and_replace(&tmp, &list);
        // printf("\nafter iter : %s\n", tmp->value);
        // lst_print(tmp);
        // printf("\nlist : \n");
        // lst_print(list);
        tmp = tmp->next;
    }
    return list;
}
