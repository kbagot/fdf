/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:35:33 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/10 17:16:04 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
//	int		x1;
//	int		y1;
	int		**map;
//	int		i;
//	int		j;
//	int		test = 0;
	int		l;

	l = 0;
//	i = 0;
//	j = 0;
//	x1 = 140;
//	y1 = 90;
	map = NULL;
	if (!mlx)
		mlx = mlx_init();
	if (argc == 2)
	{
		map = stock_map(map, argv, l);
		l = find_data(argv, l);
		fdf_fill(map, mlx, l);
	}
/*	while (i < l) // affichage of stock.
	{
		test = 0;
		j = 0;
		while (j <= map[i][0])
		{
			printf("%d", map[i][test]);
			test++;
			j++;
		}
		printf("\n");
		i++;
	}*/
	mlx_loop(mlx);
}
