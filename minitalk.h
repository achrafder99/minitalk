/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:41:47 by adardour          #+#    #+#             */
/*   Updated: 2022/12/25 21:41:33 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/libftprintf.h"
# include "libft/libft.h"
# include "signal.h"
# include <locale.h>
# include <time.h>
# include <wchar.h>

# define ERROR "\033[0;31m"
# define DISPLAY_ERROR1 "❌ Please Enter The Correct Arguments <\e[1mThe Argument must be equal 3>\n"
# define DISPLAY_ERROR2 "❌ \033[0;31mPlease Enter The Correct (Proccess ID)PID\n"
# define DISPLAY_ERROR3 "❌ \033[0;31mPlease Enter The Correct (Proccess ID)PID\n"
# define DISPLAY_ERROR4 "❌ \033[0;31mTherese Some Error Please Handle it\n"

#endif