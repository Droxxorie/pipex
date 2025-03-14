/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:04:23 by eraad             #+#    #+#             */
/*   Updated: 2025/03/14 15:01:13 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *str, char *arg)
{
	if (!str || !arg)
		return ;
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	if (arg)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	return ;
}
