/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 19:46:20 by neprocur          #+#    #+#             */
/*   Updated: 2015/08/22 23:03:51 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			check_backslash(t_shell *sh1, int *boul, char **arg)
{
	if ((sh1->arg[0][0] == '/') && (access(sh1->arg[0], F_OK) == 0))
	{
		*boul = 1;
		if ((access(sh1->arg[0], X_OK) == 0))
		{
			check_the_check(sh1, sh1->arg[0], arg, sh1->path);
			return (0);
		}
	}
	return (-1);
}

int			check_command(char *cmd_test, int *boul, char **arg, t_shell *sh1)
{
	if (access(cmd_test, F_OK) == 0)
	{
		*boul = 1;
		if (access(cmd_test, X_OK) == 0)
		{
			check_the_check(sh1, cmd_test, arg, sh1->path);
			return (0);
		}
	}
	return (-1);
}

int			check_path_two(char **path, char **arg, t_shell *sh1,
		char *cmd_test)
{
	int		i;
	int		boul;

	i = 0;
	boul = 0;
	while (sh1->path[i])
	{
		cmd_test = ft_strdup(sh1->path[i]);
		cmd_test = ft_strjoin(cmd_test, "/");
		cmd_test = ft_strjoin(cmd_test, arg[0]);
		if (check_backslash(sh1, &boul, arg) == 0)
			break ;
		if (check_command(cmd_test, &boul, arg, sh1) == 0)
			break ;
		cmd_test ? free(cmd_test) : 0;
		i++;
	}
	if (boul == 0)
	{
		ft_putstr(sh1->arg[0]);
		ft_putendl(": Command not found.");
	}
	return (0);
}

int			check_path(char **path, char **arg, t_shell *sh1)
{
	char	*cmd_test;

	path = path;
	if (sh1->arg[0][0] == '\0')
		return (0);
	if (sh1->path != NULL)
	{
		check_path_two(path, arg, sh1, cmd_test);
	}
	return (0);
}
