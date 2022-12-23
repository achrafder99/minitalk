/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:29:02 by adardour          #+#    #+#             */
/*   Updated: 2022/12/23 21:24:36 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



static void handler(int sign,siginfo_t *info,void *context){
    
    static int i = 0; 
    static unsigned int cc;
    static int STOP;
    static int j;
    
    cc |= (sign == SIGUSR1);
    
    if(i == 7){
        ft_putchar_fd(cc,1);
        i = 0;
        cc = 0;
    }
    else{
        cc <<= 0x01;
        i++;
    }
    ft_putchar_fd('\n',1);
    ft_putnbr_fd(cc,1);
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

    if(sigaction(SIGUSR1,&sigaction__,0) == -1)
        ft_putstr_fd("❌ \033[0;31mPlease Some Errors At signal (SIGUSR1)\n",1);
    if(sigaction(SIGUSR2,&sigaction__,0) == -1)
       ft_putstr_fd("❌ \033[0;31mPlease Some Errors At signal (SIGUSR2)\n",1);
    while(1){
        pause();
    }
}