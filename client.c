/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:37:30 by adardour          #+#    #+#             */
/*   Updated: 2022/12/23 21:18:21 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void action(int sign);

static void get_bytes(int pid,char *pyload){
	int i;
	int j;
	int c;
	
	i = 7;
	j = 0;
	c = 0;
	size_t  length_of_pyload = ft_strlen(pyload);
	
	while(*pyload != '\0'){
		i = 8;
		while(i-- > 0){
			if(*pyload & 1 << i){
				ft_putchar_fd('1',1);
				if(kill(pid,SIGUSR1) == -1){
					ft_putstr_fd("❌ \033[0;31mPlease Enter The Correct (Proccess ID)PID\n",1);
					exit(EXIT_FAILURE);
				}
			}
			else{
				ft_putchar_fd('0',1);
				if(kill(pid,SIGUSR2) == -1){
					ft_putstr_fd("❌ \033[0;31mPlease Enter The Correct (Proccess ID)PID\n",1);
					exit(EXIT_FAILURE);
				}
			}
			if(i == 0){
				c++;
			}
            usleep(100);
		}
		pyload++;
	}
}


int	main(int argc, char **argv)
{	
	signal(SIGUSR2,&action);
	if(argc == 3){
		get_bytes(atoi(argv[1]), argv[2]);
	}
	else{
		ft_putstr_fd(ERROR,1);
		ft_putstr_fd("❌ Please Enter The Correct Arguments <\e[1mThe Argument must be equal 3>\n",1);
	}
	return (0);
}
static void action(int sign) {
	// static int count;
	// static int j;
	// if(sign == SIGUSR2){
	// 	count++;
	// }
	// j++;
	
	
	ft_putstr_fd("\n",1);
	time_t t;  
	time(&t);
	ft_putstr_fd("\033[0;32m The message Send with success \n",1);
	ft_putstr_fd("\033[0;34m",1);
	ft_putstr_fd(" At :",1);
	ft_putstr_fd(ctime(&t),1);
	ft_putstr_fd(" PID of client :",1);
	ft_putnbr_fd(getpid(),1);
	ft_putstr_fd("\n",1);
	ft_putstr_fd("\n",1);
	exit(EXIT_SUCCESS);
}