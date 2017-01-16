/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:35:55 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/16 15:49:10 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define ix 6//space
# define iy 0.8//space
# define xvarl 4.5//newline
# define yvarl 2.8//newline
# define xorigin 900//start
# define yorigin 50//start


typedef struct	fdf_list
{
	void		*mlx;
	void		*win;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			i;
	int			j;
}				var_list;

typedef struct	line_m
{
	int		 i;
	int		xinc;
	int		yinc;
	int		cumul;
	int		x;
	int		y;
	int		dx;
	int		dy;
}				var_line;

void		draw_line(char *line, int x1, int y1);
int			main(int argc, char **argv);
int			**stock_map(int **map, char **argv, int l);
int			find_data(char **argv, int l);
void		fdf_fill(int **map, int l, var_list *var);
int			key_lol(int keycode, var_list *var);

#endif
