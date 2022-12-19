/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:24:49 by adardour          #+#    #+#             */
/*   Updated: 2022/10/22 21:23:00 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigitis(int n)
{
	c	count;

	count.countdigitis = 0;
	if (n < 0)
		count.countdigitis = 1;
	while (n != 0)
	{
		n = n / 10;
		count.countdigitis++;
	}
	return (count.countdigitis);
}

static char	*itoa_(int number, char *str, char *buffer)
{
	int	i;
	int	length;

	i = 0;
	i = 0;
	while (number > 0)
	{
		str[i] = number % 10 + 48;
		number = number / 10;
		i++;
	}
	str[i] = '\0';
	length = ft_strlen(str);
	i = 0;
	if (buffer[i] == '-')
		i += 1;
	while (length - 1 >= 0)
	{
		buffer[i] = str[length - 1];
		length--;
		i++;
	}
	return (buffer);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numberofdigitis;
	char	*buffer;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
	{
		buffer = (char *)malloc(sizeof(char) * 2);
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	numberofdigitis = countdigitis(n);
	str = (char *)malloc((numberofdigitis * sizeof(char)) + 1);
	buffer = ft_calloc(numberofdigitis, sizeof(char));
	if (str == NULL)
		return (NULL);
	else if (n < 0)
	{
		buffer[0] = '-';
		n *= -1;
	}
	return (itoa_(n, str, buffer));
}
