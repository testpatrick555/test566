/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:33:03 by achappui          #+#    #+#             */
/*   Updated: 2023/10/05 20:53:57 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	option_c_maj(int argc, char **argv)
{
	char	*option;
	int		i = 1;
	int		option_count;

	option = "-C";
	option_count = 0;
	while (i < argc)
	{
		if (ft_strcmp(option, argv[i]) == 0)
			option_count++;
		i++;
	}
	return (option_count);
}

