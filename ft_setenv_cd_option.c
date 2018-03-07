/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_cd_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 17:38:42 by neprocur          #+#    #+#             */
/*   Updated: 2015/08/19 19:44:12 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		ft_setenv_cd_option(t_shell *sh1, int i, int n)
{
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
		else
		{
			sh1->env_cpy[i] = ft_strnew(ft_strlen(sh1->arg[1]) +
					(ft_strlen(sh1->arg[2] + 2)));
			ft_strcpy(sh1->env_cpy[i], sh1->arg[1]);
			ft_strcat(sh1->env_cpy[i], "=");
			ft_strcat(sh1->env_cpy[i], sh1->arg[2]);
			i++;
			sh1->env_cpy[i] = NULL;
		}
	}
}
