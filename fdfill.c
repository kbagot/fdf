/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:43:48 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/16 19:00:21 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_var(t_line *varl, t_var *var)
{
	varl->x = var->x1;
	varl->y = var->y1;
	varl->xinc = ((var->x2 - var->x1) > 0) ? 1 : -1;
	varl->yinc = ((var->y2 - var->y1) > 0) ? 1 : -1;
	varl->dx = fabs((double)var->x2 - (double)var->x1);
	varl->dy = fabs((double)var->y2 - (double)var->y1);
}

static void	ft_line_maker_h(t_var *var, t_line *varl)
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
		mlx_pixel_put(var->mlx, var->win, varl->x, varl->y, 0x0000FFFF);
		varl->i++;
	}
}

static void	ft_line_maker(t_var *var, t_line *varl)
{
	ft_init_var(varl, var);
	if (!var->win)
		var->win = mlx_new_window(var->mlx, 2400, 1200, "fdf");
	mlx_pixel_put(var->mlx, var->win, varl->x, varl->y, 0x0000FFFF);
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

static void	ft_put_cross(int **map, t_var *var, t_line *varl)
{
	var->x1 = XORIGIN + ((-XVARL * var->i) + (IX * var->j));
	var->y1 = YORIGIN + ((YVARL * var->i) + (IY * var->j));
	if (map[var->i][var->j] > 0)
		var->y1 += -map[var->i][var->j] / 2;
	var->x2 = XORIGIN + ((-XVARL * var->i) + (IX * (var->j + 1)));
	var->y2 = YORIGIN + ((YVARL * var->i) + (IY * (var->j + 1)));
	if (map[var->i][var->j + 1] > 0)
		var->y2 += -map[var->i][var->j + 1] / 2;
	if (var->j < map[var->i][0])
		ft_line_maker(var, varl);
	if (var->i > 0)
	{
		var->x2 = XORIGIN + ((-XVARL * (var->i - 1)) + (IX * var->j));
		var->y2 = YORIGIN + ((YVARL * (var->i - 1)) + (IY * var->j));
		if (map[var->i - 1][var->j] > 0)
			var->y2 += -map[var->i - 1][var->j] / 2;
		if (var->j <= map[var->i - 1][0])
			ft_line_maker(var, varl);
	}
}

void		fdf_fill(int **map, int l, t_var *var)
{
	t_line *varl;

	var->i = 0;
	var->win = NULL;
	varl = (t_line*)malloc(sizeof(t_line));
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
