/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:45:50 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/05 11:27:54 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_command(t_pipex *pipex, char *argv, char **env)
{
	int i = 0;
	pipex->cmd = ft_split(argv, ' ');
	pipex->exc_cmd = ft_check_excute(pipex->cmd[0], env);
	return ;
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int	argv_count;

	argv_count = 2;
	//if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		//ft_here_doce();
	pipex.infile_fd = open(argv[1], O_RDWR);
	pipex.outfile_fd = open(argv[argc - 1], O_RDWR | O_TRUNC);
	dup2(pipex.infile_fd , STDIN_FILENO);
	while (argv[argv_count++])
	{
		if (argv[argv_count + 2] == NULL)
			break;
		ft_get_command(&pipex, argv[argv_count], env);
		ft_child_process(env, &pipex);
	}
	ft_get_command(&pipex, argv[argv_count], env);
	dup2(pipex.outfile_fd, STDOUT_FILENO);
	execve(pipex.exc_cmd, pipex.cmd, env);
	close (pipex.infile_fd);
	close (pipex.outfile_fd);
	return (0);
}