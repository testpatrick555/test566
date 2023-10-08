/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:57:42 by achappui          #+#    #+#             */
/*   Updated: 2023/10/05 21:17:01 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	ft_display_file(int fd)
{
	char	buf[4096];
	int		size;

	while ((size = read(fd, buf, sizeof(buf))) != 0)
		write(1, buf, size);
}

void	ft_pustr_out(char *str, int out)
{
	while (*str != '\0')
	{
		write(out, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	buf;

	i = 0;
	while (++i < argc)
	{
		fd = open(basename(argv[i]), O_RDONLY);
		if (fd < 0)
			ft_pustr_out(strerror(errno), 2);
		else
		{
			ft_display_file(fd);
			close(fd);
		}
	}
	if (argc == 1)
	{
		while (read(0, &buf, 1) != 0)
			write(1, &buf, 1);
	}
}
