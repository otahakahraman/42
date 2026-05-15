/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:15:52 by okahrama          #+#    #+#             */
/*   Updated: 2026/05/02 13:20:33 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	char	*r_value;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	r_value = malloc(i + (stash[i] == '\n') + 1);
	if (!r_value)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		r_value[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		r_value[i] = '\n';
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new = malloc(ft_strlen(stash) - i + 1);
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*read_and_join(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !have_next_line(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
			return (free(buffer), NULL);
		stash = tmp;
	}
	free(buffer);
	if (bytes < 0)
		return (free(stash), NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	stash = read_and_join(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
