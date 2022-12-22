/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:29:02 by adardour          #+#    #+#             */
/*   Updated: 2022/12/22 20:39:00 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int pid_client;

static void handler(int sign,siginfo_t *info,void *context){
    
    static int i = 0; 
    static unsigned int cc;
    
    cc |= (sign == SIGUSR1);
    
    if(i == 0x07){
        write(1,&cc,1);
        i = 0;
        cc = 0;
    }
    else{
        cc <<= 0x01;
        i++;
    }
    pid_client = info->si_pid;
}

static void display_info(pid_t pid){
    
    time_t t;  
    time(&t);

    ft_puts("\033[0;33m====================================\n");
    ft_putchar('\n');
    sleep(1);

    ft_puts("   ✅ Server Starting at: #");
    sleep(1);
    ft_putnbr_fd(pid,1);
    ft_putchar('\n');
    ft_puts("   ✅ by Achraf Dardour (@adardour)\n");
    sleep(1);
    ft_putstr_fd("   ✅ At :",1);
    ft_putstr_fd(ctime(&t),1);
    ft_putchar('\n');
    ft_puts("====================================\n");
    sleep(1);
    ft_putstr_fd("          We Waiting You ... 🕛\n",1);
    ft_puts("\033[0;37m");
    ft_putchar('\n');
    int i = 1;
    ft_putstr_fd("Message Of Client: ",1);
}

int main(){
    struct sigaction sigaction__ ;
    static pid_t pid;
    pid = getpid();
    
    display_info(pid);
    sigemptyset(&sigaction__.sa_mask);
    sigaction__.sa_flags = SA_SIGINFO;
    sigaction__.sa_sigaction = &handler;
    static int i = 0;

    sigaction(SIGUSR1,&sigaction__,0);
    sigaction(SIGUSR2,&sigaction__,0);
    while(1){
        pause();
    }
}