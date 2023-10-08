/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:57:16 by achappui          #+#    #+#             */
/*   Updated: 2023/10/06 13:04:26 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DESCENDING 1
#define ASCENDING 0

void    swap_elem(int j, char **tab)
{
    char    *swap;

    swap = tab[j - 1];
    tab[j - 1] = tab[j];
    tab[j] = swap;
}

void sort_As_Des(char **tab, int mod)
{
    int    i;
    int    j;

    i = 1;
    while (tab[i] != 0)
    {
        j = i;
		if (mod == ASCENDING)
		{
			while (j > 0 && ft_strcmp(tab[j - 1], tab[j]) > 0)
			{
				swap_elem(j, tab);
				j--;
			}
		}
        else if (mod == DESCENDING)
		{
			while (j > 0 && ft_strcmp(tab[j - 1], tab[j]) < 0)
			{
				swap_elem(j, tab);
				j--;
			}
		}
        i++;
    }
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	diff;

	i = 0;
	if (tab != 0)
	{
		if (tab[1] != 0)
		{
			while (tab[++i] != 0)
			{
				diff = cmp(tab[i - 1], tab[i]);
				if (diff < 0)
				{
					sort_As_Des(tab, DESCENDING);
					return;
				}
				else if (diff > 0)
				{
					sort_As_Des(tab, ASCENDING);
					return;
				}
			}
		}
	}
}

// #include <stdlib.h>
// #include <stdio.h>
// int    ft_strcmp(char *s1, char *s2)
// {
//     int    i;

//     i = 0;
//     while (s1[i] != '\0' || s2[i] != '\0')
//     {
//         if (s1[i] != s2[i])
//             return (s1[i] - s2[i]);
//         i++;
//     }
//     return (0);
// }

// int	main(void)
// {
// 	int i;
// 	char	*char_tab[5] = {"test2", "test1", "test3", "test4", NULL};
// 	int (*cmp)(char *, char *);
// 	cmp = &ft_strcmp;
// 	ft_advanced_sort_string_tab(char_tab, cmp);

// 	i = 0;
// 	while (i < 5)
// 	{
// 		if (char_tab[i] == NULL)
// 			printf("(null)\n");
// 		else
// 			printf("%s\n", char_tab[i]);
// 		i++;
// 	}
// }