/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:16 by eraad             #+#    #+#             */
/*   Updated: 2025/03/13 15:29:16 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	parse_cmd_args(t_pipex *pipex, char **argv)
{
	int		i;
	int		start;
	char	**cmd_args;

	pipex->cmd_args = ft_calloc(sizeof(char *), pipex->cmd_count);
	if (!pipex->cmd_args)
		return (false);
	i = 0;
	start = 2 + pipex->here_doc;
	while (i < pipex->cmd_count)
	{
		cmd_args = ft_split(argv[start + i], ' ');
		if (!cmd_args)
		{
			ft_free_2d_str_array(pipex->cmd_args, pipex->cmd_count);
			free(pipex->cmd_args);
			pipex->cmd_args = NULL;
			return (false);
		}
		pipex->cmd_args[i] = cmd_args;
		i++;
	}
	return (true);
}
