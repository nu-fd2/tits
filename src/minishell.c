/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/06/15 19:58:11 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void manager(t_data *data, char *line)
{
    t_input *input;
    t_short *shart;

    // checker(line);
    input = tokenize(line);
    filter(input);
    seperator(input);
    input = money_expansion(input);
    input = star_expansion(input);
    input = striper(input);
    lst_print(input);
    shart = last_lst_creater(input);
    lst_print2(shart);
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
        return 0;
    }
    if(!line[0])
        return (free(line), 1);
    add_history(line);
    if(ft_strcmp(line, "exit") == 0)
        return (free(line), 0);
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
    // printf("\e[1;31mam about blauw\e[0m\n");
    // struct sigaction    s_sig;
    t_data  *data;

    data = ft_calloc(1, sizeof(t_data));
    data->env = int_env(env);
    data->fd = 1;
    lvl_env(data);
    signal(SIGINT, hnd_sig);
	signal(SIGQUIT, SIG_IGN);

    atexit(t);
    // ft_memset(&s_sig, 0, sizeof(s_sig));
    // s_sig.sa_sigaction = hnd_sig;
    // s_sig.sa_flags = SA_SIGINFO;
    // sigaction(SIGINT, &s_sig, NULL);
    // sigaction(SIGQUIT, &s_sig, NULL);

    while(1)
    {
        if(prompt_msg(data) == 0)
        {
            fre_env(data->env);
            free(data);
            return 0;
        }
    }
    fre_env(data->env);
    free(data);
    return 1;
}