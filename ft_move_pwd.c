/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 19:54:15 by neprocur          #+#    #+#             */
/*   Updated: 2015/08/19 19:37:08 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_move_pwd(char *pwd, t_shell *sh1)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * 4);
	args[0] = ft_strdup("change directory");
	args[1] = ft_strdup("PWD");
	args[2] = ft_strdup(pwd);
	args[3] = NULL;
	sh1->arg = args;
	setenv_cd(sh1);
	free(args[0]);
	free(args[1]);
	free(args[2]);
	free(args);
}
