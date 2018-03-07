/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 15:42:22 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/18 02:33:15 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int				ft_access(char *path)
{
	if (access(path, F_OK) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(path);
	}
	else if ((access(path, X_OK | R_OK)) == -1)
	{
		ft_putstr("cd : permission denied: ");
		ft_putendl(path);
	}
	return (0);
}

char			*env_to_str(t_shell *sh1, char const *str)
{
	char		**env;
	int			i;

	i = 0;
	env = NULL;
	if (sh1 && str)
	{
		if ((env = sh1->env_cpy))
		{
			while (env[i])
			{
				if (!ft_strncmp(env[i], str, ft_strlen(str)))
					return (env[i]);
				i++;
			}
		}
	}
	return (NULL);
}

void			ft_new_var_cd(t_shell *sh1, char *var)
{
	int			i;
	int			n;

	i = 0;
	sh1->tabl = sh1->env_cpy;
	sh1->env_cpy = (char**)malloc(sizeof(char*) * (tablen(sh1->tabl) + 2));
	while (sh1->tabl[i] != NULL)
	{
		sh1->env_cpy[i] = ft_strdup(sh1->tabl[i]);
		i++;
	}
	sh1->env_cpy[i] = ft_strdup(var);
	i++;
	sh1->env_cpy[i] = NULL;
}

void			ft_actualise(t_shell *sh1, char *dir)
{
	char		pathpwd[256];
	char		*tmp;
	int			ret;
	int			old;
	int			pwd;

	old = ft_search2(sh1, "OLDPWD");
	pwd = ft_search2(sh1, "PWD");
	getcwd(pathpwd, 256);
	tmp = ft_strjoin("OLDPWD=", pathpwd);
	if (ft_access(dir) == 0)
	{
		chdir(dir);
		if (old != -1)
			sh1->env_cpy[ft_search2(sh1, "OLDPWD")] = tmp;
		else
			ft_new_var_cd(sh1, tmp);
		getcwd(pathpwd, 256);
		if (pwd != -1)
			sh1->env_cpy[ft_search2(sh1, "PWD")] = ft_strjoin("PWD=", pathpwd);
		else
			ft_new_var_cd(sh1, ft_strjoin("PWD=", pathpwd));
	}
}

int				ft_cd(t_shell *sh1)
{
	char		*home;
	char		*pwd;
	char		*old_pwd;

	if (sh1->arg[0] && sh1->arg[1] && sh1->arg[2])
		ft_next2(sh1);
	if (!sh1->arg[1] || sh1->arg[1][0] == '~')
	{
		if ((home = env_to_str(sh1, "HOME=")) != NULL)
			ft_actualise(sh1, home + 5);
		else
			ft_actualise(sh1, &(sh1->home[5]));
	}
	else if (sh1->arg[1] && !ft_strcmp(sh1->arg[1], "-"))
	{
		if ((old_pwd = env_to_str(sh1, "OLDPWD=")) != NULL)
			ft_actualise(sh1, old_pwd + 7);
		else
			ft_putendl("no oldpwd");
	}
	else if (sh1->arg[1] && *sh1->arg[1])
		ft_actualise(sh1, sh1->arg[1]);
	return (0);
}
