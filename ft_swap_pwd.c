/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 16:55:54 by neprocur          #+#    #+#             */
/*   Updated: 2015/07/26 17:37:30 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_swap_pwd(t_shell *sh1)
{
	int		i;
	char	oldpwd[256];
	char	pwd[256];
	char	**tmp;

	i = 0;
	while (sh1->env_cpy[i])
	{
		if (ft_strncmp(sh1->env_cpy[i], "OLDPWD=", 6) == 0)
			ft_strcpy(oldpwd, sh1->env_cpy[i]);
		if (ft_strncmp(sh1->env_cpy[i], "PWD=", 3) == 0)
			ft_strcpy(pwd, sh1->env_cpy[i]);
		i++;
	}
	if ((chdir(&oldpwd[7])) != -1)
	{
		tmp = sh1->arg;
		ft_move_pwd(&oldpwd[7], sh1);
		ft_move_oldpwd(&pwd[4], sh1);
		sh1->arg = tmp;
	}
}
