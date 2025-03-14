/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:43:02 by eraad             #+#    #+#             */
/*   Updated: 2025/03/14 11:51:27 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cleanup(t_pipex *pipex)
{
	if (pipex->in_file_fd != -1)
		close(pipex->in_file_fd);
	if (pipex->out_file_fd != -1)
		close(pipex->out_file_fd);
	if (pipex->paths != NULL)
		ft_free_str_array(pipex->paths, -1);
	if (pipex->cmd_paths != NULL)
		ft_free_str_array(pipex->cmd_paths, -1);
	if (pipex->cmd_args != NULL)
		ft_free_2d_str_array(pipex->cmd_args, pipex->cmd_count);
	if (pipex->here_doc)
		unlink(HERE_DOC_PATH);
	if (pipex->invalid_in_file)
		unlink(INVALID_IN_FILE_PATH);
}
