/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:53:07 by adardour          #+#    #+#             */
/*   Updated: 2022/12/25 22:20:08 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			g_length;

static void	action(int sign)
{
	static int	i;
	time_t		t;

	(void)sign;
	i++;
	if (i == g_length)
	{
		time(&t);
		ft_putstr_fd("\033[0;32m The message Send with success \n", 1);
		ft_putstr_fd("\033[0;34m", 1);
		ft_putstr_fd(" At :", 1);
		ft_putstr_fd(ctime(&t), 1);
		ft_putstr_fd(" PID of client :", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("\n", 1);
		exit(EXIT_SUCCESS);
	}
}

static void	send_bytes_(pid_t pid, const char *pyload)
{
	int	i;

	i = 0x07;
	while (i >= 0x00)
	{
		if ((*pyload >> i) & 0x01)
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
		i--;
		usleep(550);
	}
}

static void	extract_bytes(pid_t pid, char *pyload)
{
	while (*pyload != '\0')
	{
		send_bytes_(pid, pyload);
		pyload++;
	}
	kill(pid, SIGUSR2);
}

int	main(int c, char **v)
{
	signal(SIGUSR1, action);
	if (c == 3)
	{
		g_length = ft_strlen(v[2]);
		ft_putchar_fd('\n', 1);
		ft_putstr_fd(" Data Is Loading...\n", 1);
		extract_bytes(ft_atoi(v[1]), v[2]);
		while (1)
			pause();
	}
	else
	{
		ft_putstr_fd(ERROR, 1);
		ft_puts(DISPLAY_ERROR1);
	}
}
