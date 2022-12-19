/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:46:22 by adardour          #+#    #+#             */
/*   Updated: 2022/10/22 17:49:20 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	i = 0;
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst1 == src1 || n == 0)
		return (dst1);
	else if (dst1 == NULL && src1 == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
