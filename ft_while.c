/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/03 14:19:06 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/14 20:13:11 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		ft_while(t_shell *sh1, char **env, char **av)
{
	while (42)
	{
		ft_update_env(sh1);
		prompt();
		if ((get_next_line(0, &(sh1->cmd))) == 0)
		{
			ft_putendl("exit");
			exit(-1);
		}
		sh1->path = split_env(sh1);
		if (sh1->cmd)
		{
			sh1->arg = epur_cmd(sh1->cmd);
			if (sh1->arg[0] != NULL)
			{
				if (ft_strcmp(sh1->arg[0], "exit") == 0)
				{
					ft_putendl("exit");
					return (0);
				}
				ft_builtins(sh1, sh1->arg);
			}
		}
	}
	return (0);
}
