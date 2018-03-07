/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:09:25 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/04 22:32:34 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		ft_unsetenv(t_shell *sh1)
{
	int		i;
	int		j;

	j = 1;
	sh1->k = 0;
	if (!sh1->arg[0])
		return (-1);
	while (sh1->arg[j])
	{
		i = 0;
		sh1->k = 0;
		sh1->tabl = (char **)malloc(sizeof(char *) * (tablen(sh1->env_cpy)));
		while (sh1->env_cpy[i])
		{
			if (ft_strncmp(sh1->env_cpy[i], sh1->arg[j],
						ft_strlen(sh1->arg[j])) != 0)
				sh1->tabl[sh1->k++] = ft_strdup(sh1->env_cpy[i]);
			i++;
		}
		j++;
		sh1->tabl[sh1->k] = NULL;
		free(sh1->env_cpy);
		sh1->env_cpy = sh1->tabl;
	}
	return (0);
}
