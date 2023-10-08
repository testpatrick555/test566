/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:27:07 by achappui          #+#    #+#             */
/*   Updated: 2023/10/05 20:42:05 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MALLOC_ERROR 1
#define OPPEN_ERROR 1
#define CLOSE_ERROR 2

int file_error(int which)
{
    switch (which)
	{
    	case OPPEN_ERROR:
			write(2, "File failed to open.\n", 21);
			break;
    	case CLOSE_ERROR:
			write(2, "File failed to close.\n", 22);
	}
	return (-1);
    
}

int	malloc_error()
{
	write(2, "Memory allocation failed.\n", 26);
	return (-1);
}

int file_size(char *file_name)
{
    char	buffer[4096];
	int		size;
	int		test;
	int		fd;

	size = 0;
    if ((fd = open(file_name, O_RDONLY)) == -1)
        return (file_error(OPPEN_ERROR));
	while ((test = read(fd, buffer, sizeof(buffer))) != 0) //faut-il aussi checker la lecture?
		size = test;
    if (close(fd) == -1)
        return (file_error(CLOSE_ERROR));
	return (size);
}

char    *file_content(char *file_name, int size)
{
	char	*content;
	int		fd;

	if ((content = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (malloc_error());
    if ((fd = open(file_name, O_RDONLY)) == -1)
        return (file_error(OPPEN_ERROR));
	read(fd, content, size); //faut-il aussi checker la lecture?
    if (close(fd) == -1)
        return (file_error(CLOSE_ERROR));
	content[size] = '\0';
	return (content);
}

