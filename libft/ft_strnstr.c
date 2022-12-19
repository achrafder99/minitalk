/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:04:50 by adardour          #+#    #+#             */
/*   Updated: 2022/10/23 12:37:45 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	find;

	if ((haystack == NULL || needle == NULL) && len == 0)
		return (NULL);
	i = 0;
	j = 0;
	find = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			find++;
			if (needle[j] == '\0')
			return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
