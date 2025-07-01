/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd2 <fd2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:06:48 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/30 14:29:31 by fd2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

int sec_exc(t_data *data, t_short *shart, int in, int ot)
{
    data->fd = ot;
    data->fd2 = in;
    if (shart->reds)
        man_red(data, shart->reds);
    ex_rish(data, shart->args);
    if (data->fd != 1)
        close(data->fd);
    if (data->fd2 != 0)
        close(data->fd2);
    data->fd = 1;
    data->fd2 = 0;
}

int main_exc(t_data *data, t_short *shart)
{
    t_short *fart;
    // t_pips  *poop;
    // int     sz;
    int     in;
    int     ot;

    in = 0;
    ot = 1;
    fart = shart;
    // sz = int_pip(data, shart);
    // if (sz == 0)
    //     return (sec_exc(data, fart, 0, 1), 0);
    // poop = data->pips;
    // while (fart)
    // {
    //     ot = poop->o_pip;
    //     in = poop->i_pip;
        sec_exc(data, fart, in, ot);
        // poop = poop->next;
        // fart = fart->next;
    // }
    // clr_pip(data);
	return 0;
}
