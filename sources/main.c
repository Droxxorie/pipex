/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:54:24 by eraad             #+#    #+#             */
/*   Updated: 2025/03/14 00:02:43 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	// pipex = malloc(sizeof(t_pipex));
	// if (!pipex)
	// 	return (print_error("malloc failed"));
	init_pipex_struct(&pipex);
	if (check_args(&pipex, argc, argv) == false)
		return (cleanup(&pipex), print_error("invalid arguments"), 0);
	if (check_envp(&pipex, "PATH", envp) == false)
		return (cleanup(&pipex), print_error("PATH not found"), 0);
	if (parse_cmd_args(&pipex, argv) == false)
		return (cleanup(&pipex), print_error("wrong syntax"), 0);
	if (parse_cmd_paths(&pipex) == false)
		return (cleanup(&pipex), print_error("command path not found"), 0);
	if (pipex_logic(&pipex, envp) == false)
		return (cleanup(&pipex), print_error("pipex failed"), 0);
	return (cleanup(&pipex), 0);
}
