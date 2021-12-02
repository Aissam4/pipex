/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:45:50 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/02 16:24:14 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (ft_check_command(&pipex, argv, env) == 0)
		exit(EXIT_FAILURE);
	if (pipe(pipex.pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pipex.infile_fd = open(argv[1], O_RDWR | O_CREAT);
	pipex.outfile_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC);
	pipex.pid = fork();
	if (pipex.pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pipex.pid == 0)
		ft_child_process(&pipex, env);
	else
		ft_parent_process(&pipex, env);
	close (pipex.infile_fd);
	close (pipex.outfile_fd);
	return (0);
}
