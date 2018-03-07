/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minish1ell1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 01:32:52 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/14 18:54:31 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_init_env(t_shell *sh1, char **env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!env || !*env)
	{
		ft_update_env(sh1);
		return ;
	}
	sh1->env_cpy = (char **)malloc(sizeof(char *) * (tablen(env) + 2));
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 4) == 0)
			sh1->home = ft_strdup(env[i]);
		sh1->env_cpy[i] = ft_strdup(env[i]);
		i++;
	}
	sh1->env_cpy[i] = NULL;
}

void	sig_manage(void)
{
	int i;

	i = 1;
	while (i <= 31)
	{
		signal(i, SIG_IGN);
		i++;
	}
}

int		main(int ac, char **av, char **env)
{
	t_shell		*sh1;
	int			i;

	i = 0;
	sig_manage();
	sh1 = (t_shell *)malloc(sizeof(t_shell));
	ft_init_env(sh1, env);
	ft_while(sh1, sh1->env_cpy, av);
	return (0);
}
