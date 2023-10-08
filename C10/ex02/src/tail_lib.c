/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:06:53 by achappui          #+#    #+#             */
/*   Updated: 2023/10/05 21:29:21 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail_lib.h"

void	ft_pustr_out(char *str, int out)
{
	while (*str != '\0')
	{
		write(out, str, 1);
		str++;
	}
}

void	print_tail_cont(char *file_name, int size, int max)
{
	char	*f_cont;
	char	*pointer;
	int		fd;
	int		line_nb;

	if (size > 0)
	{
		f_cont = (char *)malloc((size + 1) * sizeof(char));
		fd = open(file_name, O_RDONLY);
		read(fd, f_cont, size);
		close(fd);
		line_nb = 1;
		f_cont[size] = '\0';
		pointer = f_cont;
		while (size > 0 && line_nb <= 10 && max > 0)
		{
			size--;
			if (f_cont[size] == '\n')
				line_nb++;
			max--;
		}
		pointer += size;
		ft_pustr_out(pointer, 1);
		free(f_cont);
	}
}

int	file_size(char *file_name)
{
	char	buffer[4096];
	int		size;
	int		test;
	int		fd;

	test = 0;
	size = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (-1);
	while ((test = read(fd, buffer, 4096)) != 0)
		size = test;
	if (close(fd) < 0)
		return (-1);
	return (size);
}

void	file_error(char *file_name)
{
	ft_pustr_out("tail: cannot open '", 2);
	ft_pustr_out(file_name, 2);
	ft_pustr_out("' for reading: ", 2);
	ft_pustr_out(strerror(errno), 2);
	write(1, "\n", 2);
}
