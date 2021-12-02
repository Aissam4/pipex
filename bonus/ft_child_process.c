/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:20:01 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/01 16:31:09 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex *pipex, char **env)
{
	close(pipex->pipefd[R]);
	dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(pipex->pipefd[W], STDOUT_FILENO);
	close(pipex->pipefd[W]);
	execve(pipex->exc_path_1, pipex->cmd_1, env);
}
