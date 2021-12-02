/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:58:57 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/01 16:42:37 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_command(t_pipex *pipex, char **argv, char **env)
{
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
	pipex->exc_path_1 = ft_check_excute(pipex->cmd_1[0], env);
	if (!pipex->exc_path_1)
		return (0);
	pipex->exc_path_2 = ft_check_excute(pipex->cmd_2[0], env);
	if (!pipex->exc_path_2)
		return (0);
	return (1);
}
