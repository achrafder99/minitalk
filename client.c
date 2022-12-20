/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:11:09 by adardour          #+#    #+#             */
/*   Updated: 2022/12/20 21:08:27 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void static send_bytes(int pid,char *bytes){
	int i;

	int j = 1;
	while(*bytes){
		i = 7;

		while(i >= 0){
			if(*bytes == '0'){
				kill(pid,SIGUSR1);
			}		
			else{
				kill(pid,SIGUSR2);
			}
			j++;
			i--;
			usleep(100);
			bytes++;
		}
		bytes++;
	}
	// 011000010110001101101000011100100110000101100110\0
}

static void get_bytes(int pid,char *pyload){
	int i;
	i = 7;
	int j;
	j = 0;
	size_t  length_of_pyload = ft_strlen(pyload);

	char *bytes;
	bytes = malloc((ft_strlen(pyload) * 8) + 1);
	
	while(*pyload != '\0'){
		i = 7;
		while(i >= 0){
			if(*pyload & 1 << i){
				bytes[j] = '1';
			}
			else{
				bytes[j] = '0';
			}
			j++;
			i--;
		}
		pyload++;
	}
	bytes[length_of_pyload * 8] = '\0';
	send_bytes(pid,bytes);
}

int	main(int argc, char **argv)
{	
	printf("%d\n",getpid());
	if(argc == 3){ 
		get_bytes(ft_atoi(argv[1]), argv[2]);
	}
	// while(1)
	// 	sleep(1);
	return (0);
}
