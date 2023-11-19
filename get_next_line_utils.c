/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 03:39:46 by root              #+#    #+#             */
/*   Updated: 2023/11/13 03:39:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if ((char)c == str[i])
			return ((char *)str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strjoin_mod(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	char		*out;

	if (!str2)
		return (NULL);
	out = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (out == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1 && str1[i])
		out[j++] = str1[i++];
	i = 0;
	while (str2[i])
		out[j++] = str2[i++];
	out[j] = '\0';
	free(str1);
	return (out);
}
