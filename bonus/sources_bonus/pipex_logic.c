/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:20:07 by eraad             #+#    #+#             */
/*   Updated: 2025/03/13 23:20:07 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static t_bool	child_process(t_pipex *pipex,
	int index, int pipe_fd[2], char **envp)
{
	if (index == 0)
	{
		if (dup2(pipex->in_file_fd, STDIN_FILENO) == -1)
			return (FALSE);
	}
	else
		if (dup2(pipex->previous_fd, STDIN_FILENO) == -1)
			return (FALSE);
	if (index == pipex->cmd_count - 1)
	{
		if (dup2(pipex->out_file_fd, STDOUT_FILENO) == -1)
			return (FALSE);
	}
	else
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			return (FALSE);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (pipex->cmd_args[index][0] == NULL)
		return (print_error("command not found", NULL), FALSE);
	if (execve(pipex->cmd_paths[index], pipex->cmd_args[index], envp) == -1)
		return (print_error("command not found",
				pipex->cmd_args[index][0]), FALSE);
	return (FALSE);
}

static t_bool	parent_process(t_pipex *pipex, int pipe_fd[2])
{
	close(pipe_fd[1]);
	if (pipex->previous_fd != -1)
		close(pipex->previous_fd);
	pipex->previous_fd = pipe_fd[0];
	return (TRUE);
}

t_bool	pipex_logic(t_pipex *pipex, char **envp)
{
	int	pid;
	int	pipe_fd[2];
	int	index;

	index = 0;
	while (index < pipex->cmd_count)
	{
		if (pipe(pipe_fd) == -1)
			return (FALSE);
		pid = fork();
		if (pid == 0)
			if (child_process(pipex, index, pipe_fd, envp) == FALSE)
				return (FALSE);
		if (parent_process(pipex, pipe_fd) == FALSE)
			return (FALSE);
		index++;
	}
	if (pipex->previous_fd != -1)
		close(pipex->previous_fd);
	index = -1;
	while (index++ < pipex->cmd_count)
		wait(NULL);
	return (TRUE);
}
