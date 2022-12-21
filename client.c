/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:37:30 by adardour          #+#    #+#             */
/*   Updated: 2022/12/21 18:54:35 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void get_bytes(int pid,char *pyload){
	int i;
	i = 7;
	int j;
	j = 0;
	size_t  length_of_pyload = ft_strlen(pyload);
	
	while(*pyload != '\0'){
		i = 7;
		while(i >= 0){
			if(*pyload & 1 << i)
				kill(pid,SIGUSR1);
			else
				kill(pid,SIGUSR2);
			j++;
			i--;
            usleep(100);
		}
		pyload++;
	}
}

int	main(int argc, char **argv)
{	
	printf("%d\n",getpid());
	if(argc == 3){ 
		get_bytes(atoi(argv[1]), argv[2]);
	}
	// while(1)
	// 	sleep(1);
	return (0);
}