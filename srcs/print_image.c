/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 07:04:01 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/25 14:56:50 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

static void	put_tile(t_info *info, t_ptr *ptr, unsigned int x, unsigned int y)
{
	unsigned int	loc;

	loc = y * info->width + x;
	if (info->map[loc] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->wall_ptr, loc % info->width * 64, loc / info->width * 64);
	if (info->map[loc] == '0' || info->map[loc] == 'E'
		|| info->map[loc] == 'C' || info->map[loc] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, x * 64, y * 64);
}

void	put_image(t_info *info, t_ptr *ptr, unsigned int x, unsigned int y)
{
	unsigned int	loc;

	loc = y * info->width + x;
	put_tile(info, ptr, x, y);
	if (info->map[loc] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->exit_ptr, x * 64, y * 64);
	if (info->map[loc] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->collect_ptr, x * 64, y * 64);
	if (info->map[loc] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player_ptr[1], x * 64, y * 64);
}

void	print_image(t_info *info, t_ptr *ptr)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			put_image(info, ptr, x, y);
			x++;
		}
		y++;
	}
}

static void	set_count(t_sprite *sprite)
{
	if (sprite->count++ > 5000)
		sprite->count = 0;
}

int	print_sprite_image(t_sprite *sprite)
{
	unsigned int	p;
	unsigned int	w;
	int				i;

	i = -1;
	p = sprite->info->player;
	w = sprite->info->width;
	if (sprite->count % 2500 == 0)
		i = sprite->count / 2500;
	if (i > 0)
	{
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->tile_ptr, (p % w) * 64, (p / w) * 64);
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->player_ptr[i - 1], (p % w) * 64, (p / w) * 64);
	}
	set_count(sprite);
	return (0);
}
