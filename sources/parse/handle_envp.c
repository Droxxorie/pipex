/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:42:05 by eraad             #+#    #+#             */
/*   Updated: 2025/03/12 23:42:05 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char **handle_envp(char *key, char **envp)
{
	int i;
	char **result;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], key, ft_strlen(key)) && envp[i][ft_strlen(key)] == '=')
		{
			result = ft_split(envp[i] + ft_strlen(key) + 1, ':');
			if (!result)
				return (NULL);
			return (result);
		}
		i++;
	}
	return (NULL);
}
