/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 12:29:43 by neprocur          #+#    #+#             */
/*   Updated: 2015/07/27 20:12:47 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*epur_str(char *str)
{
	char	*src;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((src = malloc(sizeof(char *) * ft_strlen(str))) == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
				i = i + 1;
			if (j > 0 && str[i] != '\0')
				src[j++] = ' ';
		}
		src[j] = str[i];
		j = j + 1;
		i = i + 1;
	}
	src[j] = '\0';
	return (src);
}
