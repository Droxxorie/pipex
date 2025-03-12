/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:54:24 by eraad             #+#    #+#             */
/*   Updated: 2025/03/12 17:49:41 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (print_error("malloc failed"));
	init_pipex_struct(&pipex);
	if (!check_args(&pipex, argc, argv))
		return (cleanup(&pipex), print_error("invalid arguments"));
	// TODO: parse paths
	//TODO: parse cmd args
	//TODO: pipex logic
}
