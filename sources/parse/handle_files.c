/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:30:12 by eraad             #+#    #+#             */
/*   Updated: 2025/03/14 14:41:01 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_here_doc(char *limiter)
{
	int		fd;
	char	*buffer;

	fd = open(HERE_DOC_PATH, O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("here_doc> ", STDOUT_FILENO);
	buffer = get_next_line(STDIN_FILENO);
	while (buffer)
	{
		if (ft_strncmp(buffer, limiter, ft_strlen(limiter)) == 0
			&& ft_strlen(buffer) == ft_strlen(limiter) + 1)
		{
			free(buffer);
			break ;
		}
		ft_putstr_fd(buffer, fd);
		free(buffer);
		ft_putstr_fd("here_doc> ", STDOUT_FILENO);
		buffer = get_next_line(STDIN_FILENO);
	}
	close(fd);
}

//* Check if in_file exist, is redable
int	handle_in_file(t_pipex *pipex, char **argv)
{
	if (pipex->here_doc)
	{
		handle_here_doc(argv[2]);
		pipex->in_file_fd = open(HERE_DOC_PATH, O_RDONLY);
	}
	else
	{
		if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		{
			ft_putstr_fd("Error: input file does not exist or cannot be read\n",
				STDERR_FILENO);
			pipex->in_file_fd = open(INVALID_IN_FILE_PATH,
					O_RDWR | O_CREAT | O_TRUNC, 0644);
			pipex->invalid_in_file = TRUE;
		}
		else
			pipex->in_file_fd = open(argv[1], O_RDONLY);
	}
	return (pipex->in_file_fd);
}

int	handle_out_file(t_pipex *pipex, int argc, char **argv)
{
	if (pipex->here_doc)
		pipex->out_file_fd = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->out_file_fd = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (pipex->out_file_fd);
}
