/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:26:43 by jerhee          #+#    #+#             */
/*   Updated: 2023/03/24 18:26:45 by jerhee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	check_rectangle(t_info *info)
{
	if (info->height * info->width != ft_strlen(info->map))
		print_error("Map must be rectangle!");
}

void	check_wall(t_info *info)
{
	unsigned int	i;
	unsigned int	map_len;

	i = 0;
	map_len = ft_strlen(info->map);
	while (i < map_len)
	{
		if (i < info->width || i % info->width == info->width - 1
			|| i % info->width == 0 || i >= map_len - info->width)
		{
			if (info->map[i] != '1')
				print_error("Map must be surrounded by walls!");
		}
		i++;
	}
}

void	check_element(t_info *info)
{
	unsigned int	i;

	i = 0;
	while (i++ < ft_strlen(info->map))
	{
		if (info->map[i] == 'E')
			info->exit++;
		else if (info->map[i] == 'C')
			info->collect++;
		else if (info->map[i] == 'P')
		{
			if (info->player > 0)
				print_error("Map must have one starting position!");
			else
				info->player = i;
		}
	}
}

static void	recursive(t_info *info, char *map, unsigned int cur)
{
	if (map[cur] == 'E')
		info->exit_dfs = 1;
	else if (map[cur] == 'C')
		info->collect_dfs++;
	map[cur] = '1';
	if (map[cur - info->width] != '1')
		recursive(info, map, cur - info->width);
	if (map[cur + 1] != '1')
		recursive(info, map, cur + 1);
	if (map[cur + info->width] != '1')
		recursive(info, map, cur + info->width);
	if (map[cur - 1] != '1')
		recursive(info, map, cur - 1);
}

void	check_finish(t_info *info)
{
	info->map_dfs = ft_strdup(info->map);
	recursive(info, info->map_dfs, info->player);
	if (!info->exit_dfs || info->collect != info->collect_dfs)
		print_error("Map that cannot be cleared!");
	free(info->map_dfs);
	info->map_dfs = NULL;
}
