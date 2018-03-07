/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 14:47:23 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/14 18:56:50 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		check_the_check(t_shell *sh1, char *cmd_test, char **arg, char **path)
{
	pid_t	pid;

	pid = fork();
	path = path;
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (!(execve(cmd_test, arg, sh1->env_cpy)))
			ft_putendl("Command not found.");
	}
	else
		wait(NULL);
	return (1);
}
