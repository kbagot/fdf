/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:43:48 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/10 17:16:01 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void init_line(int **map, var_list *var)
{
/*	if (var->j != 0 && var->i == 0)//coordonner of the first
	{
		if (map[var->i][var->j] == 0)
		{
			var->x1 += var->j * ix;
			var->y1 += var->j * iy;
		}*/
/*		else
		{
			var->x2 = var->x2 + 0.8 * map[var->i][var->j];
			var->y2 = (var->y2 + (0.8/2) * map[var->i][var->j]);
		}*/
//	}
//	if (map[var->i][var->j + 1] == 0)//coord 2nd
//	{
		var->x2 += var->x1 + ix;
		var->y2 += var->y1 + iy;
//	}
/*	else
	{
		var->x2 = var->x2 + 0.8 * map[var->i][var->j + 1];
		var->y2 = (var->y2 + (0.8/2) * map[var->i][var->j + 1]);
	}*/
}

static void	init_colum(int **map, var_list *var)
{
	if (var->i > 0 && map[var->i][var->j] == 0)//coord 2nd
	{
		var->x2 += (var->j) * ix;
		var->y2 += (var->j) * iy;
	}
	else
	{
		var->x2 = var->x2 + 0.8 * map[var->i - 1][var->j];
		var->y2 = (var->y2 + (0.8/2) * map[var->i - 1][var->j]);
	}
}

static void	ft_put_cross(void *mlx, int **map, var_list *var)
{
	int		x;
	int		tmpx;
	int		tmpy;

	printf("%d\n", var->i);
	x = var->x1;
	if (!var->win)
		var->win = mlx_new_window(mlx, 500, 500, "fdf");
	var->x2 = var->x1 + ix;
	var->y2 = var->y1 + iy;
//	printf("%d\n", var->x2);
//	printf("%d\n", var->y2);
//	init_line(map, var);
	while (x <= var->x2)
	{
		mlx_pixel_put(mlx, var->win, x, var->y1+((var->y2-var->y1)*(x-var->x1))
				/(var->x2-var->x1), 0x00EE2C2C);
		mlx_pixel_put(mlx, var->win, 120, 30, 0x00FFFFFF);
		x++;
	}
	tmpx = var->x2;
	tmpy = var->y2;
	if (var->i > 0)
	{
		if (map[var->i][var->j] == 0)//coord 2nd
		{
			var->x2 = var->xstart + xvarl + ((var->j - 1) * ix);
			var->y2 = var->ystart - yvarl + ((var->j - 1) * iy);
		}
		else
		{
			var->x2 = var->x2 + 0.8 * map[var->i - 1][var->j];
			var->y2 = (var->y2 + (0.8/2) * map[var->i - 1][var->j]);
		}
//		init_colum(map, var);
		x = var->x1;
		while (x <= var->x2)
		{
			mlx_pixel_put(mlx, var->win, x, var->y1+((var->y2-var->y1)*(x-var->x1))
					/(var->x2-var->x1), 0x000FFFFF);
			x++;
		}
	}
	var->x1 = tmpx;
	var->y1 = tmpy;
}

void		fdf_fill(int **map, void *mlx , int l)
{
	var_list *var;

	var = (var_list*)malloc(sizeof(var_list));
	var->i = 0;
	var->win = NULL;
	var->xstart = 120;
	var->ystart = 30;
	var->x1 = var->xstart;
	var->y1 = var->ystart;
	while (var->i < l)
	{
		var->j = 1;
		while (var->j < map[var->i][0])
		{
			ft_put_cross(mlx, map, var);
			var->j++;
		}
		var->x1 = var->xstart - xvarl;// start new line
		var->y1 = var->ystart + yvarl;
		var->xstart = var->x1;
		var->ystart = var->y1;
		var->i++;
	}
}
