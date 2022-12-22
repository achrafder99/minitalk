/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:37:30 by adardour          #+#    #+#             */
/*   Updated: 2022/12/22 20:20:01 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static void action(int sign){
	time_t t;  
    time(&t);
	ft_putstr_fd("\033[0;32m The message Send with success✅\n",1);
	ft_putstr_fd("\033[0;34m",1);
	ft_putstr_fd(" At :",1);
	ft_putstr_fd(ctime(&t),1);

}

static void get_bytes(int pid,char *pyload){
	int i;
	int j;
	int c;
	
	i = 7;
	j = 0;
	c = 0;
	size_t  length_of_pyload = ft_strlen(pyload);
	
	while(*pyload != '\0'){
		i = 7;
		while(i >= 0){
			if(*pyload & 1 << i){
				if(kill(pid,SIGUSR1) == -1)
					exit(EXIT_FAILURE);
			}
			else{
				if(kill(pid,SIGUSR2) == -1)
					exit(EXIT_FAILURE);
			}
			j++;
			i--;
			if(i == 0){
				c++;
			}
            usleep(100);
		}
		pyload++;
	}
	if(c == length_of_pyload){
		action(SIGUSR1);
		exit(EXIT_SUCCESS);
	}
}


int	main(int argc, char **argv)
{	
	
	if(argc == 3){ 
		get_bytes(atoi(argv[1]), argv[2]);
	}
	else{
		ft_putstr_fd(ERROR,1);
		ft_putstr_fd("❌ Please Enter The Correct Arguments\n",1);
	}
	// while(1)
	// 	sleep(1);
	return (0);
}