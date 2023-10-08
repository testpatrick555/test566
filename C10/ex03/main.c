/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:56:50 by achappui          #+#    #+#             */
/*   Updated: 2023/10/05 20:49:49 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		file_size(char *file_name);
char    *file_content(char *file_name, int size);
int		option_c_maj(int argc, char **argv);
void	print_hexdump_c_maj(char *reader, char	*line, int size);
void	print_hexdump(char *reader, int size);

int	main(int argc, char **argv)
{
	char	*content;
	int		size;

	

}