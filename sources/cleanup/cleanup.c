/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:43:02 by eraad             #+#    #+#             */
/*   Updated: 2025/03/12 17:46:28 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	cleanup(t_pipex *pipex)
{
	if (pipex->in_file_fd != -1)
		close(pipex->in_file_fd);
	if (pipex->out_file_fd != -1)
		close(pipex->out_file_fd);
	if (pipex->envp != NULL)
		//TODO: free_array(array, shape)
	if (pipex->cmd_args != NULL)
		//TODO: free_array(array, shape)
	if (pipex->here_doc)
		unlink(HERE_DOC_PATH);
	if (pipex->invalid_in_file)
		unlink(INVALID_IN_FILE_PATH);
	free(pipex);
}
