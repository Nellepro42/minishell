/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 19:35:20 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/14 18:13:11 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_get(t_shell *sh1)
{
	char	*pwd;

	pwd = getwd(NULL);
	ft_putendl(pwd);
	ft_strdel(&pwd);
}

int		ft_builtins(t_shell *sh1, char **arg)
{
	if (sh1->arg[0])
	{
		if (ft_strcmp(sh1->arg[0], "env") == 0)
			write_env(sh1);
		else if (ft_strcmp(sh1->arg[0], "setenv") == 0)
			ft_setenv(sh1);
		else if (ft_strcmp(sh1->arg[0], "unsetenv") == 0)
			ft_unsetenv(sh1);
		else if (ft_strcmp(sh1->arg[0], "cd") == 0)
			ft_cd(sh1);
		else if (ft_strcmp(sh1->arg[0], "pwd") == 0)
			ft_get(sh1);
		else if (ft_strchr(sh1->arg[0], '/'))
			check_the_check(sh1, sh1->arg[0], sh1->arg, sh1->env_cpy);
		else if (sh1->arg[0])
			check_path(sh1->path, sh1->arg, sh1);
		else
			ft_putendl("Command not found.");
	}
	sh1->cmd ? free(sh1->cmd) : 0;
	return (0);
}
