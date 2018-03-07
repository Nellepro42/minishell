/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 19:40:47 by neprocur          #+#    #+#             */
/*   Updated: 2015/07/26 16:31:18 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	**split_env(t_shell *sh1)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	while (sh1->env_cpy[i])
	{
		if (ft_strncmp("PATH=", sh1->env_cpy[i], 5) == 0)
		{
			tab = ft_strsplit(&sh1->env_cpy[i][5], ':');
			break ;
		}
		i++;
	}
	return (tab);
}
