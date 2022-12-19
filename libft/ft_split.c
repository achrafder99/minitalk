/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:34:32 by adardour          #+#    #+#             */
/*   Updated: 2022/10/21 15:32:30 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getrows(char const *s, char delimiter)
{
	char	*trim;
	int		count;
	int		stop;

	count = 1;
	trim = ft_strtrim(s, &delimiter);
	while (*trim != '\0')
	{
		if (*trim == delimiter)
			stop = 0;
		else if (stop == 0)
		{
			stop = 1;
			count++;
		}
		++trim;
	}
	return (count);
}

static int	getcolumn(char *str, char delimiter, int index)
{
	int	length;

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

void	fill(char *trim, char **ptr, int row, char c)
{
	int	i;
	int	j;
	int	jj;

	i = 0;
	j = 0;
	jj = 0;
	while (row > j)
	{
		while (trim[i] != c && trim[i] != '\0')
		{
			ptr[j][jj] = trim[i];
			if (ptr[j] == NULL)
				return ((void)(NULL));
			i++;
			jj++;
		}
		i += 1;
		if (trim[i] != c)
		{
			ptr[j][jj] = '\0';
			jj = 0;
			j++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	int		i;
	int		j;
	char	**ptr;
	char	*trim;

	if (s == NULL)
		return (NULL);
	words = getrows(s, c);
	i = 0;
	j = 0;
	trim = ft_strtrim(s, &c);
	ptr = (char **)malloc(sizeof(char *) * (words + 1));
	if (ptr == NULL)
		return (NULL);
	while (trim[j] != '\0')
	{
		while (words > 0)
		{
			if (trim[j] == c)
				break ;
			ptr[i] = (char *)malloc(sizeof(char) * getcolumn(trim, c, j) + 1);
			if (ptr[i] == NULL)
			{
				free(ptr);
				return (NULL);
			}
			i++;
			j += getcolumn(trim, c, j);
			words--;
		}
		j++;
	}
	if (ft_strlen(ft_strtrim(s, &c)) == 0)
	{
		words = 0;
		ptr[words] = NULL;
		return (ptr);
	}
	words = getrows(s, c);
	fill(trim, ptr, words, c);
	ptr[words] = NULL;
	return (ptr);
}
