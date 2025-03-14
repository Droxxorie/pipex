/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:54:24 by eraad             #+#    #+#             */
/*   Updated: 2025/03/14 16:43:53 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	init_pipex_struct(&pipex);
	if (check_args(&pipex, argc, argv) == FALSE)
		return (cleanup(&pipex), print_error("invalid arguments", "\0"), 0);
	if (check_envp(&pipex, "PATH", envp) == FALSE)
		return (cleanup(&pipex), print_error("PATH not found", "\0"), 0);
	if (parse_cmd_args(&pipex, argv) == FALSE)
		return (cleanup(&pipex), print_error("wrong syntax", "\0"), 0);
	if (parse_cmd_paths(&pipex) == FALSE)
		return (cleanup(&pipex), 0);
	if (pipex_logic(&pipex, envp) == FALSE)
		return (cleanup(&pipex), 1);
	return (cleanup(&pipex), 0);
}
