/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:29:02 by adardour          #+#    #+#             */
/*   Updated: 2022/12/24 20:46:51 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Explain Global Variables
unsigned int	g_numbers[8];

void	fillarray(void)
{
	g_numbers[0] = 128;
	g_numbers[1] = 64;
	g_numbers[2] = 32;
	g_numbers[3] = 16;
	g_numbers[4] = 8;
	g_numbers[5] = 4;
	g_numbers[6] = 2;
	g_numbers[7] = 1;
}

static void	handler(int sign, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	decimal;

	fillarray();
	if (sign == SIGUSR1)
		decimal += g_numbers[i];
	i++;
	if (i == 8)
	{
		ft_putchar_fd(decimal, 1);
		i = 0;
		decimal = 0;
	}
}

static void	display_info(pid_t pid)
{
	time_t	t;
	int		i;

	time(&t);
	ft_puts("\033[0;33m====================================\n");
	ft_putchar('\n');
	sleep(1);
	ft_puts("   ✅ Server Starting at: #");
	sleep(1);
	ft_putnbr_fd(pid, 1);
	ft_putchar('\n');
	ft_puts("   ✅ by Achraf Dardour (@adardour)\n");
	sleep(1);
	ft_putstr_fd("   ✅ At :", 1);
	ft_putstr_fd(ctime(&t), 1);
	ft_putchar('\n');
	ft_puts("====================================\n");
	sleep(1);
	ft_putstr_fd("          We Waiting You ... 🕛\n", 1);
	ft_puts("\033[0;37m");
	ft_putchar('\n');
	i = 1;
}

int	main(void)
{
	struct sigaction	sigaction__;
	static pid_t		pid;
	static int			i;

	pid = getpid();
	display_info(pid);
	sigemptyset(&sigaction__.sa_mask);
	sigaction__.sa_flags = SA_SIGINFO;
	sigaction__.sa_sigaction = &handler;
	i = 0;
	while (1)
	{
		if (sigaction(SIGUSR1, &sigaction__, 0) == -1)
			ft_puts("❌ \033[0;31mPlease Some Errors At signal (SIGUSR1)\n");
		if (sigaction(SIGUSR2, &sigaction__, 0) == -1)
			ft_puts("❌ \033[0;31mPlease Some Errors At signal (SIGUSR2)\n");
		pause();
	}
}
