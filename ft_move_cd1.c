/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cd1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 16:05:30 by neprocur          #+#    #+#             */
/*   Updated: 2015/07/27 18:53:36 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_move_cd1(t_shell *sh1, char *pwd)
{
	char	buff[256];
	char	**tmp;

	tmp = NULL;
	getcwd(buff, 256);
	tmp = sh1->arg;
	ft_move_pwd(buff, sh1);
	ft_move_oldpwd(&pwd[4], sh1);
	sh1->arg = tmp;
}
