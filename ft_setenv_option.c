/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 17:38:42 by neprocur          #+#    #+#             */
/*   Updated: 2015/08/21 23:33:43 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		ft_setenv_option2(t_shell *sh1, int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		sh1->tabl = sh1->env_cpy;
		sh1->env_cpy = (char**)malloc(sizeof(char*) * (tablen(sh1->tabl) + 2));
		while (sh1->tabl[i])
		{
			sh1->env_cpy[i] = ft_strdup(sh1->tabl[i]);
			i++;
		}
		sh1->env_cpy[i] = (char *)malloc(sizeof(char) * ft_strlen(sh1->arg[1])
				+ ft_strlen(sh1->arg[2] + 2));
		ft_strcpy(sh1->env_cpy[i], sh1->arg[1]);
		ft_strcat(sh1->env_cpy[i], "=");
		ft_strcat(sh1->env_cpy[i], sh1->arg[2]);
		i++;
		sh1->env_cpy[i] = NULL;
	}
}

int			ft_setenv_equal(t_shell *sh1)
{
	if (ft_strchr(sh1->arg[1], '='))
	{
		ft_putendl("setenv: Syntax Error.");
		return (-1);
	}
	return (0);
}

int			ft_setenv_option(t_shell *sh1, int i, int n)
{
	ft_setenv_equal(sh1);
	if (sh1->arg[1] && sh1->arg[2])
	{
		if (n >= 0)
		{
			i = n;
			free(sh1->env_cpy[i]);
			sh1->env_cpy[i] = (char *)malloc(sizeof(char) *
					(ft_strlen(sh1->arg[1]) + (ft_strlen(sh1->arg[2]) + 2)));
			ft_strcpy(sh1->env_cpy[i], sh1->arg[1]);
			ft_strcat(sh1->env_cpy[i], "=");
			ft_strcat(sh1->env_cpy[i], sh1->arg[2]);
			i++;
		}
	}
	if (sh1->arg[3])
	{
		ft_putendl("Too many arguments");
		return (-1);
	}
	else
		ft_setenv_option2(sh1, n);
	return (0);
}
