/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:30:12 by eraad             #+#    #+#             */
/*   Updated: 2025/03/17 13:58:59 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//* Check if in_file exist, is redable
int	handle_in_file(t_pipex *pipex, char **argv)
{
	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
	{
		print_error("no such file or directory", argv[1]);
		pipex->in_file_fd = open(INVALID_IN_FILE_PATH,
				O_RDWR | O_CREAT | O_TRUNC, 0644);
		pipex->invalid_in_file = TRUE;
	}
	else
		pipex->in_file_fd = open(argv[1], O_RDONLY);
	return (pipex->in_file_fd);
}

int	handle_out_file(t_pipex *pipex, int argc, char **argv)
{
	if (access(argv[argc + 1], F_OK) == 0 && access(argv[argc - 1], W_OK) == -1)
	{
		print_error("permission denied", argv[argc - 1]);
		return (-1);
	}
	pipex->out_file_fd = open(argv[argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (pipex->out_file_fd);
}
