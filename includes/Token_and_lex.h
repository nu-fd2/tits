/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token_and_lex.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:27:37 by mdakni            #+#    #+#             */
/*   Updated: 2025/06/27 17:05:52 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_AND_LEX_H
#define TOKEN_AND_LEX_H

// #include "../ex/m_exec.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
# include <limits.h>
# include <stdint.h>
#include <sys/wait.h>

// #ifdef linux
// #include <readline/history.h>
// #include <readline/readline.h>
// #else
#include "../readline/history.h"
#include "../readline/readline.h"
// #endif


// Tokens used to categorise each word in the input string.
// R : right, L : left, S : single, D : double, O : opened, C : closed.
typedef enum s_tokens
{
    TOKEN_WORD,
    TOKEN_OP,
    TOKEN_RED_APP,
    TOKEN_DELIMITER,
    TOKEN_CMD,
    TOKEN_ARG,
    TOKEN_FILE,
    TOKEN_R_RED,
    TOKEN_L_RED,
    TOKEN_R_APP,
    TOKEN_L_APP,
    TOKEN_PIPE,
    TOKEN_O_PAR,
    TOKEN_C_PAR,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_EOF
}   t_token;


// exehshahahuwyghksp 3flwcs    py8asty7         qt;tuiow   es
// rl_kill_full_lineef s
// FJes f F SEGKLHSJS
// gmtime_r[GK;k E pr3 
// OFLWGK HR;JL ]

typedef struct s_latest t_short;

typedef struct s_data t_data;

typedef struct s_env t_env;

typedef struct s_data
{
	int				fd;
	int				fd2;
	int				ex;
	int				exm;
	pid_t			kid;
	char			**chr_env;
	t_env			*env;
    t_pips          *pips;
}					t_data;

typedef struct s_env
{
	char			*key;
	char			*value;
	bool			ported;
	struct s_env	*next;
}					t_env;

typedef struct s_pips
{
    int         i_pip;
    int         o_pip;
    t_pips      *next;
}               t_pips;

//================================================

typedef struct s_nodes
{
    int index;
    int quotes; // 0 : no problems, 1 : open single quotes, 2 : open double quotes
    int strip;
    t_token type;
    t_token category;
    bool red_app;
    bool expand;
    char *value;
    struct s_nodes *next;
    struct s_nodes *prev;
    struct s_nodes *tail;
}   t_input;

// this nigger
typedef struct s_latest
{
    char **args; // this mf
    char **reds; // ls -la | grep 'x' > outfile  -------- args == [ls] [la]
    struct s_latest *next;
    struct s_latest *prev;
    struct s_latest *tail;
    bool ambiguous;
}   t_short;

typedef struct s_size
{
    int nodes;
    int size_cmd;
    int size_red;
}   t_size;

typedef struct s_quotes
{
    int i;
    int quotes;
    int remove; // 0 : no problems, 1 : open single quotes, 2 : open double quotes
    bool expand;
}   t_quotes;

typedef struct s_flags
{
    char *string;
    char *expand;
    int quotes;
    int start;
    int end;
    int d_start;
    int d_end;
} t_flags;

typedef struct s_blah
{
    int args;
    int reds;
    int args_i;
    int reds_i;
    char **args2;
    char **reds2;
    bool ambiguous;
} t_blah;
typedef struct s_star
{
    struct dirent *data;
    struct s_star *next;
    
}   t_star;

t_input *tokenize(char *line);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, int n);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_lstadd_back(t_input **lst, char *content);
void	ft_lstadd_back_2(t_short **lst, t_blah blah);
t_input	*ft_lstlast(t_input *lst);
size_t	ft_strlen(const char *s);
void ft_lstfree(t_input *lst);
bool is_space(char c);
void	lst_print(t_input *bruh);
int prompt_msg(t_data *data);//---------
void ft_lstfree_2(t_short *lst);
t_short	*ft_lstlast_2(t_short *lst);
void	ft_lstadd_back_2(t_short **lst, t_blah blah);
void lst_assign_2(t_short **new, t_short **lst);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnjoin(char *s1, char *s2, int n);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
int handle_pipe(t_input **list, char *line);
int handle_red(t_input **list, char *line);
int handle_app(t_input **list, char *line);
int handle_quotes(t_input **list, char *line);
int handle_word(t_input **list, char *line);
bool check_limit(char *line, t_quotes *check);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void filter(t_input *list);
void checker(char *line);
void seperator(t_input *list);
t_short *transformer(t_input *list);
t_input *money_expansion(t_input *list, t_data *data);
t_input *star_expansion(t_input *list);
char	**ft_split(char const *s);
void striper(t_input *list);
void lst_print2(t_short *list);
int ft_checker(char c, int quote_flag);
t_short *last_lst_creater(t_input *lst);
void handle_clear(t_input *list, t_blah *blah);








//================================================

size_t		ft_strlen(const char *who);//
size_t		ft_strlcpy(char *dst, const char *src, size_t n);//
size_t		ft_strlcat(char *dst, const char *src, size_t n);//
void		*ft_memset(void	*ptr, int n, size_t num);//
void		ft_bzero(void *s, size_t len);//
int			ft_isdigit(int c);//
int			ft_strncmp(const char *s1, const char *s2, size_t n);//
int			ft_strcmp(const char *s1, const char *s2);//
char		*ft_strchr(const char *str, int c);//
int			ft_atoi(const char *str);//
char		*ft_itoa(int n);//
char		*ft_strdup(const char *s1);//
char		**ft_ssplit(char const *s, char c);//
void		*ft_calloc(size_t count, size_t size);//
char		*ft_ssubstr(char const *s, unsigned int start, size_t len);//
char		*ft_sstrjoin(char const *s1, char const *s2);//
void		ft_putchar_fd(char c, int fd);//
void		ft_putstr_fd(char *s, int fd);//

int	cmd_export(t_data *data, char **arg);
int	cmd_unset(t_data *data, char **arg);
int	cmd_echo(t_data *data, char **arg);
int	cmd_env(t_data *data);
int	cmd_pwd(t_data *data);
int cmd_cd(t_data *data, char **path);

t_env	*int_env(char **env);
int		prn_env(t_data *data);
int		prn_port_env(t_data *data);
int		fre_env(t_env *env);
int		del_env(t_env *env, char *key);
t_env	*grp_env(t_env *env, char *key);
char	*gky_env(t_env *env, char *key);
t_env	*add_env(t_env *env, char *key, char *value, bool ported);
int	lvl_env(t_data *data);
char	**int_chr_env(t_data *data);
void	fre_chr_env(char **env);

int	ex_rish(t_data *data, char **arg);
int	ex_synau(t_data *data, char **arg);
char    *ex_there(t_data *data, char *cmd);
int	ex_cpro(t_data *data, char *cmd, char **arg);

int	man_red(t_data *data, char **red);
int	src_red(t_data *data, char **red);
int	red_red(t_data *data, char *red);
int	apn_red(t_data *data, char *red);
int	inn_red(t_data *data, char *red);

int main_exc(t_data *data, t_short *shart);
int	int_pip(t_data *data, t_short *shart);
void    clr_pip(t_data *data);






#endif
