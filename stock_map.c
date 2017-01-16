/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:08:16 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/16 15:49:08 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			find_data(char **argv, int l)
{
	int			fd;
	char		*line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write (1, "No file ", 8);
		ft_putstr(argv[1]);
		write (1, "\n", 1);
		return (-1);
	}
	while (get_next_line(fd, &line))
		l++;
	if (l == 0)
	{	
		write (1, "No data found.\n", 15);
		return (-1);
	}
	close(fd);
	return (l);
}

static int	**make_stock(char *line, int **map)
{
	char		**str;
	static int	i = 0;
	int			j;
	int			l;

	str = NULL;
	l = 0;
	str = ft_strsplit(line, ' ');
	while (str[++l])
		map[i] = (int*)malloc(sizeof(int) * l + 1);
	map[i][0] = l;
	j = 0;
	while (str[j])
	{
		map[i][j + 1] = ft_atoi(str[j]);
		j++;
	}
	i++;
	return (map);
}

int			**stock_map(int **map, char **argv, int l)
{
	char		*line;
	int			fd;

	line = NULL;
	l = find_data(argv, l);
	if (l == -1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	map = (int**)malloc(sizeof(int*) * l);
	while (get_next_line(fd, &line))
		map = make_stock(line, map);
	return (map);
}
