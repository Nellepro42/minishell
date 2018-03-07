/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:36:43 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/14 17:46:51 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			ft_search(t_shell *sh1)
{
	int		i;

	i = 0;
	if (sh1->env_cpy)
	{
		while (sh1->env_cpy[i])
		{
			if ((ft_strncmp(sh1->env_cpy[i], sh1->arg[1],
							ft_strlen(sh1->arg[1])) == 0) &&
					(sh1->env_cpy[i][ft_strlen(sh1->arg[1])] == '='))
				return (i);
			i++;
		}
	}
	return (-1);
}
