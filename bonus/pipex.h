/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:57:17 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/05 14:08:47 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# define TRUE 1
# define W 1
# define R 0

typedef struct s_pipex
{
	char	**cmd;
	char	*exc_cmd;
	pid_t	pid;
	int		pipefd[2];
	int		infile_fd;
	int		outfile_fd;
}	t_pipex;


void		ft_get_command(t_pipex *pipex, char *argv, char **env);

void		ft_child_process(char **env, t_pipex *pipex);

static void	*ft_memzero(size_t size);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

static int	word_length(char const *s, char c);

char		**ft_split(char const *s, char c);

void		*ft_memcpy(void *dest, const void *src, size_t n);

char		*ft_strdup(const char *s);

char		*ft_strjoin(char const *s1, char const *s2);

void		*ft_memmove(void *dest, const void *src, size_t n);

size_t		ft_strlen(const char *s);

char		*ft_check_path(char **env);

char		*ft_check_excute(char *cmd, char **env);

char    	*get_next_line(int fd);

void     	ft_here_doc(char *argv, t_pipex *pipex);
#endif
