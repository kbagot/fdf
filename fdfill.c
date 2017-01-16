/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:43:48 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/16 15:49:12 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_var(var_line *varl, var_list *var)
{
	varl->x = var->x1;
	varl->y = var->y1;
	varl->xinc = ((var->x2 - var->x1) > 0) ? 1 : -1;
	varl->yinc = ((var->y2 - var->y1) > 0) ? 1 : -1;
	varl->dx = abs(var->x2 - var->x1);
	varl->dy = abs(var->y2 - var->y1);
}

static void	ft_line_maker_h(var_list *var, var_line *varl)
{
	ft_init_var(varl, var);
	varl->cumul = varl->dy / 2;
	varl->i = 1;
	while (varl->i <= varl->dy)
	{
		varl->y += varl->yinc;
		varl->cumul += varl->dx;
		if (varl->cumul >= varl->dy)
		{
			varl->cumul -= varl->dy;
			varl->x += varl->xinc;
		}
		mlx_pixel_put(var->mlx, var->win, varl->x, varl->y, 0x00FFFFFF);
		varl->i++;
	}
}

static void	ft_line_maker(var_list *var, var_line *varl)
{
	ft_init_var(varl, var);
	if (!var->win)
		var->win = mlx_new_window(var->mlx, 2400, 1200, "fdf");
	mlx_pixel_put(var->mlx, var->win, varl->x, varl->y, 0x00FFFFFF);
	if (varl->dx > varl->dy)
	{
		varl->cumul = varl->dx / 2;
		varl->i = 1;
		while (varl->i <= varl->dx)
		{
			varl->x += varl->xinc;
			varl->cumul += varl->dy;
			if (varl->cumul >= varl->dx)
			{
				varl->cumul -= varl->dx;
				varl->y += varl->yinc;
			}
			mlx_pixel_put(var->mlx, var->win, varl->x, varl->y, 0x00FFFFFF);
			varl->i++;
		}
	}
	else
		ft_line_maker_h(var, varl);
}

static void	ft_put_cross(int **map, var_list *var, var_line *varl)
{
	var->x1 = xorigin + ((-xvarl * var->i) + (ix * var->j));
	var->y1 = yorigin + ((yvarl * var->i) + (iy * var->j));
	if (map[var->i][var->j] > 0)
		var->y1 += -map[var->i][var->j] / 2;
	var->x2 = xorigin + ((-xvarl * var->i) + (ix * (var->j + 1)));
	var->y2 = yorigin + ((yvarl * var->i) + (iy * (var->j + 1)));
	if (map[var->i][var->j + 1] > 0)
		var->y2 += -map[var->i][var->j + 1] / 2;
	if (var->j < map[var->i][0])
		ft_line_maker(var, varl);
	if (var->i > 0)
	{
		var->x2 = xorigin + ((-xvarl * (var->i - 1)) + (ix * var->j));
		var->y2 = yorigin + ((yvarl * (var->i - 1)) + (iy * var->j));
		if (map[var->i - 1][var->j] > 0)
			var->y2 += -map[var->i - 1][var->j] / 2;
		if (var->j <= map[var->i - 1][0])
			ft_line_maker(var, varl);
	}
}

void		fdf_fill(int **map, int l, var_list *var)
{
	var_line *varl;

	var->i = 0;
	var->win = NULL;
	varl = (var_line*)malloc(sizeof(var_line));
	while (var->i < l)
	{
		var->j = 1;
		while (var->j <= map[var->i][0])
		{
			ft_put_cross(map, var, varl);
			var->j++;
		}
		var->i++;
	}
}
