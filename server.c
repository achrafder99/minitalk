/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:56:54 by adardour          #+#    #+#             */
/*   Updated: 2022/12/19 21:18:04 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// get The info about Client
static void
handler(int sig, siginfo_t *si, void *context)
{
    printf("%d\n",si->si_signo);
}

int main(int c,const char* argv[]){
    

    struct sigaction sa;   
    int pid;
    pid = getpid();
    ft_printf("\033[0;33mServer Starting at : \e[1m#%d\e[m\n",pid);
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    
    sigaction(SIGUSR1,&sa,0);
    sigaction(SIGUSR2,&sa,0);

    while(1){
        sleep(1);
    }
    return (0);
}