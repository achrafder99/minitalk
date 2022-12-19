/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:16:55 by adardour          #+#    #+#             */
/*   Updated: 2022/10/18 16:30:47 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bb;

	i = 0;
	bb = (unsigned char *)b;
	while (bb[i] != '\0' && len > i)
	{
		bb[i] = (unsigned char)c;
		b++;
		i++;
	}
	return (bb);
}
