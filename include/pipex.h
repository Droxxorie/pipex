/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:35 by eraad             #+#    #+#             */
/*   Updated: 2025/03/14 11:46:42 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/include/libft.h"

# define HERE_DOC_PATH ".tmp_here_doc"
# define INVALID_IN_FILE_PATH ".tmp_invalid_in_file"

//* structs
//*****************************************************************************/
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
}	t_pipex;

//* Error handling
//*****************************************************************************/
void	print_error(char *str);

//* Init struct
//*****************************************************************************/
void	init_pipex_struct(t_pipex *pipex);

//* parse
//*****************************************************************************/
t_bool	check_args(t_pipex *pipex, int argc, char **argv);
int		handle_in_file(t_pipex *pipex, char **argv);
int		handle_out_file(t_pipex *pipex, int argc, char **argv);
t_bool	check_envp(t_pipex *pipex, char *key, char **envp);
t_bool	parse_cmd_args(t_pipex *pipex, char **argv);
t_bool	parse_cmd_paths(t_pipex *pipex);

//* cleanup
//*****************************************************************************/
void	cleanup(t_pipex *pipex);

//* pipex
//*****************************************************************************/
t_bool	pipex_logic(t_pipex *pipex, char **envp);

#endif