/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:41:55 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/25 14:57:21 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../mlx/mlx.h"

static void	player_move(t_info *info, int move)
{
	if (info->map[info->player - move] != '1')
	{
		if (info->map[info->player - move] == 'C')
			info->collect--;
		if (!(info->map[info->player - move] == 'E' && info->collect != 0))
		{
			info->walk++;
			if (info->map[info->player - move] == 'E' && info->collect == 0)
				exit_game("game clear!");
			info->map[info->player - move] = 'P';
			info->map[info->player] = '0';
			info->player -= move;
			ft_printf("움직인 횟수 : %d\n", info->walk);
			put_image(info, info->ptr, (info->player + move) % info->width,
				(info->player + move) / info->width);
			put_image(info, info->ptr, info->player % info->width,
				info->player / info->width);
		}
	}
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit_game("Press ESC button!");
	else if (keycode == KEY_W)
	{
		info->ptr->player_ptr[1] = info->ptr->player_dir_ptr[2];
		player_move(info, info->width);
	}
	else if (keycode == KEY_A)
	{
		info->ptr->player_ptr[1] = info->ptr->player_dir_ptr[1];
		player_move(info, 1);
	}
	else if (keycode == KEY_S)
	{
		info->ptr->player_ptr[1] = info->ptr->player_dir_ptr[3];
		player_move(info, -info->width);
	}
	else if (keycode == KEY_D)
	{
		info->ptr->player_ptr[1] = info->ptr->player_dir_ptr[0];
		player_move(info, -1);
	}
	return (0);
}
