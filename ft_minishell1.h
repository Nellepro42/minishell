/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 16:17:03 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/18 03:27:13 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H
# define BUFF_SIZE 9999

# include "libft/libft.h"
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h> 
# define UPD_ENV_PATH "PATH=/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt"

typedef struct				s_shell
{
	int					k;
	int					b;
	char				*cmd;
	char				*buf;
	char				*home;
	char				*pwd;
	char				*oldpwd;
	char				**path;
	char				**arg;
	char				**env_cpy;
	char				**tabl;
}							t_shell;

int							get_next_line(int const fd, char **line);
void						ft_setenv(t_shell *sh1);
int							ft_unsetenv(t_shell *sh1);
int							tablen(char **tab);
int							ft_search(t_shell *sh1);
void						check_my_functions(t_shell *sh1);
int							ft_cd(t_shell *sh1);
int							ft_setenv_option(t_shell *sh1, int i, int n);
int							check_path(char **path, char **arg, t_shell *sh1);
int							check_the_check(t_shell *sh1, char *cmd_test,
							char **arg, char **path);
int							ft_builtins(t_shell *sh1, char **arg);
char						**epur_cmd(char *cmd);
void						prompt(void);
char						**split_env(t_shell *sh1);
void						ft_move_oldpwd(char *oldpwd, t_shell *sh1);
//void						ft_swap_pwd(t_shell *sh1);
void						write_env(t_shell *sh1);
int							ft_while(t_shell *sh1, char **env, char **av);
void						setenv_cd(t_shell *sh1, char *arg);
void						ft_setenv_cd_option(t_shell *sh1, int i, int n);
void						ft_args(t_shell *sh1);
void						ft_update_env(t_shell *sh1);
int							ft_search_i(t_shell *sh1);
char 						*env_to_str(t_shell *sh1, char const *str);
int							ft_search2(t_shell *sh1, char *var);
int							ft_next2(t_shell *sh1);

#endif
