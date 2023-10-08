/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:02:42 by achappui          #+#    #+#             */
/*   Updated: 2023/10/04 19:08:01 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_LIB_H
# define TAIL_LIB_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

void	ft_pustr_out(char *str, int out);
void	print_tail_cont(char *file_name, int size, int max);
void	file_error(char *file_name);
int		file_size(char *file_name);

#endif