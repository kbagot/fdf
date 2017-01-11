/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:43:48 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/11 16:20:15 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//RETURN VAR_LIST DOUCHBAG !

void	ft_put_cross(void *mlx, int **map, var_list *var)
{
	int		x;
//	int		tmpx;
//	int		tmpy;
	
	var->x1 = xorigin + ((-xvarl * var->i) + (ix * var->j));
	var->y1 = yorigin + ((yvarl * var->i) + (iy * var->j));
	if (map[var->i][var->j] > 0)
		var->y1 += -map[var->i][var->j] - 10;
	x = var->x1;
	if (!var->win)
		var->win = mlx_new_window(mlx, 800, 800, "fdf");
	var->x2 = xorigin + ((-xvarl * var->i) + (ix * (var->j + 1)));
	var->y2 = yorigin + ((yvarl * var->i) + (iy * (var->j + 1)));
	if (map[var->i][var->j + 1] > 0)
		var->y2 += -map[var->i][var->j] - 10; 
	while (x <= var->x2)
	{
		mlx_pixel_put(mlx, var->win, x, var->y1+((var->y2-var->y1)*(x-var->x1))
				/(var->x2-var->x1), 0x00EE2C2C);
		x++;
	}
	if (var->i > 0)
	{
		var->x2 = xorigin + ((-xvarl * (var->i - 1)) + (ix * var->j));
		var->y2 = yorigin + ((yvarl * (var->i - 1)) + (iy * var->j));
		if (map[var->i - 1][var->j] > 0)
			var->y2 += -map[var->i - 1][var->j] - 10;
//		var->x2 = var->xstart + xvarl + ((var->j - 1) * ix);
//		var->y2 = var->ystart - yvarl + ((var->j - 1) * iy);
		x = var->x1;
		while (x <= var->x2)
		{
			mlx_pixel_put(mlx, var->win, x, var->y1+((var->y2-var->y1)*(x-var->x1))
					/(var->x2-var->x1), 0x000FFFFF);
			x++;
		}
	}
}

void		fdf_fill(int **map, void *mlx , int l)
{
	var_list *var;

	var = (var_list*)malloc(sizeof(var_list));
	var->i = 0;
	var->win = NULL;
	var->xstart = xorigin;
	var->ystart = yorigin;
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
