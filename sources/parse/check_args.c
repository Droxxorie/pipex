/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:05:15 by eraad             #+#    #+#             */
/*   Updated: 2025/03/14 11:51:51 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	check_args(t_pipex *pipex, int argc, char **argv)
{
	if (argv[1] && !ft_strncmp(argv[1], "here_doc", 8)
		&& ft_strlen(argv[1]) == 8)
		pipex->here_doc = true;
	if (argc + pipex->here_doc < 5)
		return (false);
	if (handle_in_file(pipex, argv) == -1)
		return (false);
	if (handle_out_file(pipex, argc, argv) == -1)
		return (false);
	pipex->cmd_count = argc - pipex->here_doc - 3;
	return (true);
}
