/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:35 by eraad             #+#    #+#             */
/*   Updated: 2025/03/15 12:15:14 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//* ----------------- Includes ---------------------- *
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/include/libft.h"

//* ----------------- Macros ------------------------- *
# define HERE_DOC_PATH ".tmp_here_doc"
# define INVALID_IN_FILE_PATH ".tmp_invalid_in_file"

//* ----------------- Structs ------------------------ *
typedef struct s_pipex
{
	int		in_file_fd;
	int		out_file_fd;
	char	**paths;
	char	***cmd_args;
	char	**cmd_paths;
	int		cmd_count;
	t_bool	here_doc;
	t_bool	invalid_in_file;
	int		previous_fd;
}	t_pipex;

//* ----------------- Error handling ----------------- *
void	print_error(char *str, char *arg);

//* ----------------- Initialize struc --------------- *
void	init_pipex_struct(t_pipex *pipex);

//* ----------------- Parsing ------------------------ *
t_bool	parse_cmd_paths(t_pipex *pipex);
int		handle_in_file(t_pipex *pipex, char **argv);
t_bool	parse_cmd_args(t_pipex *pipex, char **argv);
t_bool	check_args(t_pipex *pipex, int argc, char **argv);
t_bool	check_envp(t_pipex *pipex, char *key, char **envp);
int		handle_out_file(t_pipex *pipex, int argc, char **argv);

//* ----------------- Cleanup ------------------------ *
void	cleanup(t_pipex *pipex);

//* ----------------- Forking & Pipe ----------------- *
t_bool	pipex_logic(t_pipex *pipex, char **envp);

#endif