/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:39:51 by adardour          #+#    #+#             */
/*   Updated: 2022/12/25 22:12:43 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_event(int sign, siginfo_t *info, void *context)
{
	static unsigned char	decimal;
	static int				i;
	static int				client_id;

	(void)context;
	decimal |= (sign == SIGUSR1);
	if ((client_id != info->si_pid) || !client_id)
	{
		client_id = info->si_pid;
		i = 0;
		decimal = 0;
	}
	if (i == 7)
	{
		ft_putchar_fd(decimal, 1);
		i = 0;
		decimal = 0;
		if (kill(client_id, SIGUSR1) == -1)
			ft_putstr_fd(ERROR, 1);
	}
	else
	{
		decimal <<= 1;
		i++;
	}
}

static void	display_info(pid_t pid)
{
	time_t	t;

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
}

int	main(void)
{
	struct sigaction	sa;

	display_info(getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler_event;
	sa.sa_flags = SA_SIGINFO;
	ft_putchar_fd('\n', 1);
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		ft_puts("❌ \033[0;31mPlease Some Errors At signal (SIGUSR1)\n");
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		ft_puts("❌ \033[0;31mPlease Some Errors At signal (SIGUSR2)\n");
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
