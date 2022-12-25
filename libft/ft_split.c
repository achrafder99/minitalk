/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:34:32 by adardour          #+#    #+#             */
/*   Updated: 2022/10/31 14:54:11 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getrows(char const *s, char delimiter)
{
	int		i;
	int		count;
	char	*trim;

	if (s == NULL)
		return (0);
	i = 0;
	count = 0;
	trim = ft_strtrim(s, &delimiter);
	if (trim == NULL)
		return (0);
	while (trim[i] != '\0')
	{
		while (*trim != '\0' && trim[i] == delimiter)
			i++;
		while (trim[i] != delimiter && trim[i] != '\0')
			i++;
		count++ ;
	}
	return (count);
}

static int	getcolumn(char const *str, char delimiter, int index)
{
	int	length;

	if (str == NULL)
		return (0);
	length = 0;
	while (str[index] != '\0')
	{
		if (str[index] == delimiter)
			break ;
		index++;
		length++;
	}
	return (length);
}

static void	deallocate(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static void	allocate(char *s, char c, char **split, int words)
{
	t_rowsandcolumns	rowandcolumn;

	if (s == NULL || split == NULL)
		return ;
	rowandcolumn = (t_rowsandcolumns){.i = 0, .j = 0, .nextblock = 0};
	while (words)
	{
		while (s[rowandcolumn.i] == c && s[rowandcolumn.i] != '\0')
			rowandcolumn.i++;
		rowandcolumn.j = 0;
		while (s[rowandcolumn.i] != c && s[rowandcolumn.i] != '\0')
		{
			split[rowandcolumn.nextblock][rowandcolumn.j] = s[rowandcolumn.i];
			if (split[rowandcolumn.nextblock] == NULL)
				deallocate(split);
			rowandcolumn.i++;
			rowandcolumn.j++;
		}
		split[rowandcolumn.nextblock][rowandcolumn.j] = '\0';
		words--;
		rowandcolumn.nextblock++;
	}
}

char	**ft_split(char const *s, char c)
{
	t_rowsandcolumns	randc;

	randc = (t_rowsandcolumns){.i = 0, .j = 0, .nextblock = 0, .length = 0};
	if (s == NULL)
		return (NULL);
	randc.words = getrows(s, c);
	randc.ptr = malloc((sizeof(char *) * randc.words) + 1);
	if (randc.ptr == NULL)
		return (NULL);
	while (randc.words-- > 0)
	{
		while (s[randc.i] == c && s[randc.i] != '\0')
			randc.i++;
		while (s[randc.i] != c && s[randc.i] != '\0')
		{
			randc.length = getcolumn((char *)s, (char)c, randc.i);
			randc.ptr[randc.nextblock] = malloc(randc.length + 1);
			randc.i += getcolumn(s, c, randc.i);
			randc.nextblock++;
		}
		if (randc.nextblock == getrows(s, c))
			allocate((char *)s, c, randc.ptr, getrows(s, c));
	}
	randc.ptr[randc.nextblock] = NULL;
	return (randc.ptr);
}
