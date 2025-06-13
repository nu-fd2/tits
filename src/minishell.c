/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/06/05 12:18:31 by oel-mado         ###   ########.fr       */
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
    striper(input);
    shart = last_lst_creater(input);
    lst_print2(shart);

    // TS AHHHHHHH
    //fnc(shart)
    ex_rish(data, shart->args);

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
        exit(0);
    }
    add_history(line);
    if(ft_strcmp(line, "exit") == 0)
        return 0;
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
    signal(SIGINT, hnd_sig);
	signal(SIGQUIT, SIG_IGN);

    // atexit(t);
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
        // printf("%s\n", line);
    }
    fre_env(data->env);
    free(data);
    return 1;
}