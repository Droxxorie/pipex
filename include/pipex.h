/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:35 by eraad             #+#    #+#             */
/*   Updated: 2025/03/12 17:46:45 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# define HERE_DOC_PATH ".tmp_here_doc"
# define INVALID_IN_FILE_PATH ".tmp_invalid_in_file"

//* structs
//*****************************************************************************/
typedef struct s_pipex
{
	int		in_file_fd;
	int		out_file_fd;
	char	**envp;
	char	***cmd_args;
	int		cmd_count;
	bool	here_doc;
	bool	invalid_in_file;
} t_pipex;
//*****************************************************************************/

//* Error handling
//*****************************************************************************/
int print_error(char *str);

//* Init struct
//*****************************************************************************/
void init_pipex_struct(t_pipex *pipex);

//* parse
//*****************************************************************************/
bool check_args(t_pipex *pipex, int argc, char **argv);
int handle_in_file(t_pipex *pipex, char **argv);
int handle_out_file(t_pipex *pipex, int argc, char **argv);

//* cleanup
//*****************************************************************************/
void cleanup(t_pipex *pipex);


#endif