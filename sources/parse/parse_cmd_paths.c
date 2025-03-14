/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:50:26 by eraad             #+#    #+#             */
/*   Updated: 2025/03/13 15:50:26 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *find_cmd_path(t_pipex *pipex, char *cmd)
{
	int i;
	char *cmd_path;
	char *temp;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (pipex->paths[i])
	{
		temp = ft_strjoin(pipex->paths[i], "/");
		if (!temp)
			return (NULL);
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

bool parse_cmd_paths(t_pipex *pipex)
{
	int i;

	pipex->cmd_paths = ft_calloc(sizeof(char *), pipex->cmd_count + 1);
	if (!pipex->cmd_paths)
		return (false);
	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->cmd_paths[i] = find_cmd_path(pipex, pipex->cmd_args[i][0]);
		if (!pipex->cmd_paths[i])
		{
			ft_free_str_array(pipex->cmd_paths, pipex->cmd_count + 1);
			pipex->cmd_paths = NULL;
			return (false);
		}
		i++;
	}
	return (true);
}
