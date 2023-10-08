/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:33:34 by achappui          #+#    #+#             */
/*   Updated: 2023/10/05 21:37:04 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_hexa(char c, char *hexa, char *hex_table)
{
	hexa[1] = c & 0x0F;
	hexa[0] = c >> 4;
}

void	input_offset(int index, char *hex_table)
{
	int	tab[8];
	int	i;

	i = 7;
	while (i >= 0)
	{
		tab[i] = hex_table[index & 0x0F];
		index >>= 4;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		write(1, &tab[i], 1);
		i++;
	}
}

int	char_content(char *reader)
{
	int i;

	i = 0;
	write(1, "|", 1);
	while (reader[i] != '\0')
	{
		if (reader[i] < 32 || reader[i] > 126)
			write(1, ".", 1);
		else
			write(1, &reader[i], 1);
		i++;
	}
	write(1, "|", 1);
	return (i);
}

void	half_hexa_c_maj(char *reader, char *hex_table)
{
	char	hexa[2];
	int		i;

	i = 0;
	while (i < 8)
	{
		if (*reader != '\0')
		{
			get_hexa(reader[i], hexa, hex_table);
			write(1, &hexa[0], 1);
			write(1, &hexa[1], 1);
			reader++;
		}
		else
			write(1, "  ", 2);
		if (i < 7)
			write(1, " ", 1);
		i++;
	}
}

char	*hexa_no_option(char *reader, char *hex_table)
{
	char	hexa[2];
	int		i;

	i = -2;
	while ((i += 2) < 16)
	{
		if (*reader != '\0')
		{
			get_hexa(*(reader + 1), hexa, hex_table);
			write(1, &hexa[0], 1);
			write(1, &hexa[1], 1);
			get_hexa(*reader, hexa, hex_table);
			write(1, &hexa[0], 1);
			write(1, &hexa[1], 1);
			if (*(reader + 1) == '\0')
				reader++;
			else
				reader += 2;
		}
		else
			write(1, "    ", 4);
		if (i < 14)
			write(1, " ", 1);
		return (reader);
	}
}