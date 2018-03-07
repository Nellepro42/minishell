/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_oldpwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 16:10:58 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/18 03:23:39 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_move_oldpwd(char *oldpwd, t_shell *sh1)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * 4);
	args[0] = ft_strdup("change directory");
	args[1] = ft_strdup("OLDPWD");
	args[2] = ft_strdup(oldpwd);
	args[3] = NULL;
	sh1->arg = args;
	setenv_cd(sh1, *sh1->arg);
	free(args[0]);
	free(args[1]);
	free(args[2]);
	free(args);
}
