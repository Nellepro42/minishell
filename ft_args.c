/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 05:27:55 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/05 05:31:18 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		ft_args(t_shell *sh1)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * 4);
	args[0] = ft_strdup("cd");
	args[1] = ft_strdup("PWD");
	args[2] = ft_strdup(sh1->home);
	args[3] = NULL;
	sh1->arg = args;
	ft_setenv(sh1);
	free(args);
}
