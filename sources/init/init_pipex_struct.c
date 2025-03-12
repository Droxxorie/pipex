/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:03:59 by eraad             #+#    #+#             */
/*   Updated: 2025/03/12 16:15:25 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	init_pipex_struct(t_pipex *pipex)
{
	pipex->in_file_fd = -1;
	pipex->out_file_fd = -1;
	pipex->envp = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_count = 0;
	pipex->here_doc = false;
	pipex->invalid_in_file = false;
}
