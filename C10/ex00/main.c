/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:07:04 by achappui          #+#    #+#             */
/*   Updated: 2023/10/05 21:19:04 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(int fd)
{
	char	buf[4096];
	int		size;

	while ((size = read(fd, buf, sizeof(buf))) != 0)
		write(1, buf, size);
}

int	main(int argc, char **argv)
{
	int fd;
	
	if (argc == 1)
		write(2, "File name is missing.\n", 22);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			write(2, "Cannot read file.\n", 18);
		else
		{
			ft_display_file(fd);
			close(fd);
		}
	}
}