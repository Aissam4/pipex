/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:44:31 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/05 11:20:40 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str2;
	unsigned char	*str1;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void     ft_here_doc(char *argv)
{
    char    *tmp;
    char    *buffer;
    
    buffer = calloc(1,1);
    while (TRUE)
    {
        write(1, "here_doc> ", 11);
        tmp = get_next_line(0);
        if (ft_strncmp(tmp, argv, ft_strlen(argv)) == 0)
        {
            write (1, buffer, ft_strlen(buffer));
            break ;
        }
        buffer = ft_strjoin(buffer, tmp);
    }
}
	// if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	// {
	// 	ft_here_doc(argv[2]);
	// 	if (argv[3] == NULL)
	// 		return (0);
	// 	argv_count += 1;
	// 	//return (0);
	// }