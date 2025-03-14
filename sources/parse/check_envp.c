/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:20:31 by eraad             #+#    #+#             */
/*   Updated: 2025/03/13 15:20:31 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_envp(t_pipex *pipex, char *key, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], key, ft_strlen(key)) && envp[i][ft_strlen(key)] == '=')
		{
			pipex->paths = ft_split(envp[i] + ft_strlen(key) + 1, ':');
			if (!pipex->paths)
			{
				pipex->paths = NULL;
				return (false);
			}
			return (true);
		}
		i++;
	}
	return (false);
}
