/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/03 17:32:13 by neprocur          #+#    #+#             */
/*   Updated: 2015/07/03 17:32:17 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		write_env(t_shell *sh1)
{
	int		i;

	i = 0;
	if (sh1->env_cpy[i])
	{
		while (sh1->env_cpy[i])
		{
			ft_putendl(sh1->env_cpy[i]);
			i++;
		}
	}
}
