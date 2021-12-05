/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:49:38 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/05 09:03:10 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result_tab;
	unsigned int	total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result_tab = (char *)malloc(sizeof(char) * total_len + 1);
	if (!result_tab)
		return (NULL);
	ft_memmove(result_tab, s1, ft_strlen(s1));
	ft_memmove(result_tab + ft_strlen(s1), s2, ft_strlen(s2));
	result_tab[total_len] = '\0';
	//free((char *)s1);
	return (result_tab);
}
