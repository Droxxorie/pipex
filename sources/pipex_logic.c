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

#include "pipex.h"

static bool child(t_pipex *pipex, int pipe_fd[2], int index, char **envp)
{
	if (index == 0)
	{
		if (dup2(pipex->in_file_fd, STDIN_FILENO) == -1)
			return (false);
	}
	else if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			return (false);
	if (index == pipex->cmd_count - 1)
	{
		if (dup2(pipex->out_file_fd, STDOUT_FILENO) == -1)
			return (false);
	}
	else if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			return (false);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (pipex->cmd_paths[index])
	{
		if (execve(pipex->cmd_paths[index], pipex->cmd_args[index], envp) == -1)
			return (false);
	}
	else
		return (false);
	return (true);
}

static bool parent(int *pid, int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (waitpid(*pid, NULL, 0) == -1)
		return (false);
	return (true);
}

static bool pipex_core(t_pipex *pipex, int index, char **envp)
{
	int pid;
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (false);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (false);
	}
	if (pid == 0)
	{
		if (child(pipex, pipe_fd, index, envp) == false)
			return (false);
	}
	else
		if (parent(&pid, pipe_fd) == false)
			return (false);
	return (true);
}

bool pipex_logic(t_pipex *pipex, char **envp)
{
	int index;

	index = 0;
	while (index < pipex->cmd_count)
	{
		if (pipex_core(pipex, index, envp) == false)
		{
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			ft_putstr_fd(pipex->cmd_args[index][0], STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			return (false);
		}
		index++;
	}
	return (true);
}
