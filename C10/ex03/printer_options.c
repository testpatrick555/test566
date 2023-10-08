/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:37:51 by achappui          #+#    #+#             */
/*   Updated: 2023/10/05 20:41:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	half_hexa_c_maj(char *reader, char *hex_table);
char	*hexa_no_option(char *reader, char *hex_table);

void	print_hexdump_c_maj(char *reader, char	*line, int size)
{
	char	*hex_table;
	int		i;

	hex_table = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		input_offset(i, hex_table);
		write(1, "  ", 2);
		reader = half_hexa_c_maj(reader, hex_table);
		write(1, "  ", 2);
		reader = half_hexa_c_maj(reader, hex_table);
		write(1, "  ", 2);
		char_content(line);
		line = reader;
		write(1, "\n", 1);
		i += 16;
	}
	if (size > 0)
	{
		input_offset(size, hex_table);
		write(1, "\n", 1);
	}
}

void	print_hexdump(char *reader, int size)
{
	char	*hex_table;
	int		i;

	hex_table = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		input_offset(i, hex_table);
		write(1, " ", 2);
		reader = hexa_no_option(reader, hex_table);
		write(1, "\n", 1);
		i += 16;
	}
	if (size > 0)
	{
		input_offset(size, hex_table);
		write(1, "\n", 1);
	}
}