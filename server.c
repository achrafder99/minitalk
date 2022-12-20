/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:56:54 by adardour          #+#    #+#             */
/*   Updated: 2022/12/20 21:54:42 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// get The info about Client
static void handler(int sig, siginfo_t *info, void *context)
{    
    unsigned char c;
    c |= (sig == SIGUSR1);
    printf("%d\n",c);
}


int main(int c,const char* argv[]){
    

    struct sigaction sa;   
    int pid;
    pid = getpid();
    ft_printf("\033[0;33mServer Starting at : \e[1m#%d\e[m\n",pid);
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handler;

    sigaction(SIGUSR1,&sa,0);
    sigaction(SIGUSR2,&sa,0);
    
    while(1){
        sleep(1);
    }
    return (0);
}