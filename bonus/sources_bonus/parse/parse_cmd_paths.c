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

#include "pipex_bonus.h"

static char	*find_cmd_path(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*temp;

	if (cmd)
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
	cmd_path = malloc(1);
	cmd_path[0] = '\0';
	return (cmd_path);
}

t_bool	parse_cmd_paths(t_pipex *pipex)
{
	int	i;

	pipex->cmd_paths = ft_calloc(sizeof(char *), pipex->cmd_count + 1);
	if (!pipex->cmd_paths)
		return (FALSE);
	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->cmd_paths[i] = find_cmd_path(pipex, pipex->cmd_args[i][0]);
		i++;
	}
	return (TRUE);
}
