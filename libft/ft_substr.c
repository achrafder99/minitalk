/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:25:48 by adardour          #+#    #+#             */
/*   Updated: 2022/10/22 00:18:24 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	buffer = ft_strdup(s);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (substr == NULL)
		return (NULL);
	if (start >= ft_strlen(buffer))
		return (ft_strdup(""));
	while (s[i] != '\0' && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[len] = '\0';
	return (substr);
}
