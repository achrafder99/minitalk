/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:29:02 by adardour          #+#    #+#             */
/*   Updated: 2022/12/21 19:19:25 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int sender;

static void handler(int sign,siginfo_t *info,void *context){
    static int i = 0; 
    static unsigned int cc;
    cc |= (sign == SIGUSR1);
    sender = info->si_pid;
    if(i == 7){
        write(1,&cc,1);
        i = 0;
        cc = 0;
    }
    else{
        cc <<= 1;
        i++;
    }
}

int main(){
    struct sigaction sigaction__ ;
    static pid_t pid;
    pid = getpid();
    
    ft_puts("====================================\n");

    ft_puts("   Server Starting at: #");
    ft_putnbr_fd(pid,1);
    ft_putchar('\n');
    ft_puts("====================================\n");
    ft_puts("       We Waiting you...\n\n");
    sigemptyset(&sigaction__.sa_mask);
    sigaction__.sa_flags = SA_SIGINFO;
    sigaction__.sa_sigaction = &handler;

    sigaction(SIGUSR1,&sigaction__,0);
    sigaction(SIGUSR2,&sigaction__,0);
    while(1){
        sleep(1);
    }
}