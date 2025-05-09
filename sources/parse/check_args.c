/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:05:15 by eraad             #+#    #+#             */
/*   Updated: 2025/03/17 14:01:09 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	check_args(t_pipex *pipex, int argc, char **argv)
{
	if (argc != 5)
		return (FALSE);
	if (handle_in_file(pipex, argv) == -1)
		return (FALSE);
	if (handle_out_file(pipex, argc, argv) == -1)
		return (FALSE);
	pipex->cmd_count = argc - 3;
	return (TRUE);
}
