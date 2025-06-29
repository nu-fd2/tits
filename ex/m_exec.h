/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 05:18:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/25 17:27:53 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_EXEC_H
#define M_EXEC_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>

#include "libft/libft.h"
#include "m_bul/bul_cmd.h"
#include "m_env/env.h"
#include "m_exc/ex_exc.h"

#include "../includes/Token_and_lex.h"

typedef struct s_latest t_short;

typedef struct s_data t_data;

typedef struct s_env t_env;

typedef struct s_data
{
	int				fd;
	int				ex;
	int				ext; // ext = Extreme Xtra Tits = $?
	t_env			*env;
}					t_data;

// void	hnd_sig(int signum, siginfo_t *info, void *cnt);

// int prompt_msg();

// void	hnd_sig(int signum, siginfo_t *info, void *cnt);

#endif // M_EXEC_H
