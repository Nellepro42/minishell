/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:17:56 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/18 03:14:55 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		ft_setenv_cd_cd(char *arg, t_shell *sh1, char *buf)
{
	int		i;

	i = 0;
	while (sh1->env_cpy[i])
		i++;
	sh1->env_cpy[i] = ft_strnew(ft_strlen(arg) + 8);
	ft_strcat(sh1->env_cpy[i], "OLDPWD=");
	ft_strcat(sh1->env_cpy[i], getcwd(buf, 256));
	i++;
	sh1->env_cpy[i] = NULL;
}

int			ft_search2(t_shell *sh1, char *var)
{
	int		i;

	i = 0;
	if (sh1->env_cpy)
	{
		while (sh1->env_cpy[i])
		{
			if (ft_strncmp(sh1->env_cpy[i], var, ft_strlen(var)) == 0 &&
					(sh1->env_cpy[i][ft_strlen(var)] == '='))
				return (i);
			i++;
		}
	}
	return (-1);
}

void		setenv_cd(t_shell *sh1, char *arg)
{
	int		i;
	int		n_old;
	int		n_pwd;
	char	*buf;

	n_old = ft_search2(sh1, "OLDPWD");
	n_pwd = ft_search2(sh1, "PWD");
	if (n_old == -1)
		ft_setenv_cd_cd(arg, sh1, buf);
	else
		ft_strcat(sh1->env_cpy[n_old] + 7, env_to_str(sh1, "PWD="));
	i = 0;
	if (n_pwd == -1)
	{
		while (sh1->env_cpy[i])
			i++;
		sh1->env_cpy[i] = ft_strnew(ft_strlen(arg) + 8);
		ft_strcat(sh1->env_cpy[i], "PWD=");
		ft_strcat(sh1->env_cpy[i], arg);
		i++;
		sh1->env_cpy[i] = NULL;
	}
	else
		ft_strcat(sh1->env_cpy[n_pwd] + 4, arg);
	ft_setenv_cd_option(sh1, i, n_old);
}
