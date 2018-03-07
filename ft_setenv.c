/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:17:56 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/18 02:50:29 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		ft_next(t_shell *sh1)
{
	int		i;

	i = 0;
	sh1->tabl = sh1->env_cpy;
	sh1->env_cpy = (char**)malloc(sizeof(char*) * (tablen(sh1->tabl) + 2));
	while (sh1->tabl[i])
	{
		sh1->env_cpy[i] = ft_strdup(sh1->tabl[i]);
		i++;
	}
	sh1->env_cpy[i] = ft_strnew(ft_strlen(sh1->arg[1]) + 2);
	ft_strcpy(sh1->env_cpy[i], sh1->arg[1]);
	ft_strcat(sh1->env_cpy[i], "=");
	i++;
	sh1->env_cpy[i] = NULL;
}

void		ft_update_env(t_shell *sh1)
{
	if (!sh1->env_cpy || !sh1->env_cpy[0])
	{
		sh1->env_cpy = malloc(sizeof(char *) * 2);
		sh1->env_cpy[0] = ft_strdup(UPD_ENV_PATH);
		sh1->env_cpy[1] = NULL;
	}
}

void		ft_setenv(t_shell *sh1)
{
	int		i;
	int		n;

	i = 0;
	n = ft_search(sh1);
	if (sh1->arg[0] && !sh1->arg[1])
		write_env(sh1);
	else if (sh1->arg[1] && !sh1->arg[2])
	{
		if (n == -1)
			ft_next(sh1);
	}
	else
		ft_setenv_option(sh1, i, n);
}
