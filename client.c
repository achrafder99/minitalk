/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:37:30 by adardour          #+#    #+#             */
/*   Updated: 2022/12/24 20:46:10 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int sign);

static void	send_bytes(pid_t pid, char *pyload)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (*pyload & 1 << i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_puts(DISPLAY_ERROR1);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_puts(DISPLAY_ERROR3);
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
		i--;
	}
}

static void	get_bytes(int pid, char *pyload)
{
	int	j;
	int	c;

	j = 0;
	c = 0;
	while (*pyload != '\0')
	{
		send_bytes(pid, pyload);
		pyload++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		signal(SIGUSR2, action);
		get_bytes(atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_putstr_fd(ERROR, 1);
		ft_puts(DISPLAY_ERROR1);
	}
	return (0);
}

static void	action(int sign)
{
	static int	i;
	time_t		t;

	i = 1;
	if (i == 0)
		return ;
	if (sign == SIGUSR2)
	{
		while (i)
		{
			ft_putstr_fd("\n", 1);
			time(&t);
			ft_putstr_fd("\033[0;32m The message Send with success \n", 1);
			ft_putstr_fd("\033[0;34m", 1);
			ft_putstr_fd(" At :", 1);
			ft_putstr_fd(ctime(&t), 1);
			ft_putstr_fd(" PID of client :", 1);
			ft_putnbr_fd(getpid(), 1);
			ft_putstr_fd("\n", 1);
			ft_putstr_fd("\n", 1);
			i = 0;
		}
	}
}
