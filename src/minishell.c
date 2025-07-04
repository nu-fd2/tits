/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/07/01 18:21:13 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void manager(t_data *data, char *line)
{
    t_input *input;
    t_short *shart;

    // checker(line);
    input = tokenize(line);
    filter(input);
    seperator(input);
    input = money_expansion(input, data);
    input = star_expansion(input);
    striper(input);
    shart = last_lst_creater(input);

    lst_print2(shart);

    // TS AHHHHHHH
    //fnc(shart)

    main_exc(data, shart);

    // lst_print(input);
    // printf("\e[1;32mCums!\e[0m\n");
    // shart = transformer(input);
    ft_lstfree(input);
    ft_lstfree_2(shart);
}

int prompt_msg(t_data *data)
{
    char *line;
    line = readline("\e[1;32m❯ \e[0m");
    if (!line)
    {
        write(1, "exit\n", 5);
        free(line);
        // exit(0);
        return 0;
    }
    if (!line[0])
        return (free(line), 1);
    add_history(line);
    manager(data, line);
    free(line);
    return 1;
}
void t()
{
    system("leaks minishell");
}

static void hnd_sig(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	// rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int main(int ac, char **av, char **env)
{
    t_data  *data;
    int     ret;

    ret = 1;
    data = ft_calloc(1, sizeof(t_data));
    data->env = int_env(env);
    data->fd = 1;
    data->fd2 = 0;
    data->exm = 0;
    lvl_env(data);
    signal(SIGINT, hnd_sig);
	signal(SIGQUIT, SIG_IGN);

    atexit(t);

    while(69)
    {
        ret = prompt_msg(data);
        if (data->exm != 0)
        {
            ret = 0;
            break;
        }
        if (ret == 0)
            break;
    }
    fre_env(data->env);
    free(data);
    return (ret);
}
