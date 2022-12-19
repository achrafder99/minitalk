/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:38:02 by adardour          #+#    #+#             */
/*   Updated: 2022/10/12 15:50:37 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pp;
	int				j;

	i = 0;
	pp = (unsigned char *)s;
	while (i < n)
	{
		pp[i] = 0;
		i++;
	}
	j = 0;
}
