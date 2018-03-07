/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 00:03:36 by neprocur          #+#    #+#             */
/*   Updated: 2015/10/18 02:49:55 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			ft_search_i(t_shell *sh1)
{
	int		i;

	i = 0;
	if (sh1->env_cpy)
	{
		while (sh1->env_cpy[i])
		{
			if ((ft_strncmp(sh1->env_cpy[i], sh1->arg[0],
							ft_strlen(sh1->arg[0])) == 0) &&
					(sh1->env_cpy[i][ft_strlen(sh1->arg[0])] == '='))
				return (i);
			i++;
		}
	}
	return (-1);
}
