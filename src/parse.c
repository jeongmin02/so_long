/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:42:06 by changhle          #+#    #+#             */
/*   Updated: 2023/03/24 18:02:08 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

static int	parse_map(char *filename, t_info *info)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (close(fd));
	info->width = ft_strlen(str) - 1;
	delete_newline(str);
	while (str)
	{
		info->height++;
		info->map = ft_free_strjoin(info->map, str);
		if (!info->map)
			print_error("Join failed");
		str = get_next_line(fd);
		if (!str)
			return (close(fd));
		delete_newline(str);
	}
	return (0);
}

void	parse(int argc, char **argv, t_info *info)
{
	if (argc != 2)
		print_error("Parameter must have two argument!");
	else if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".ber", 4))
		print_error("Map file must have .ber extension!");
	parse_map(argv[1], info);
	check_rectangle(info);
	check_wall(info);
	check_element(info);
	if (info->exit != 1)
		print_error("Map must have one exit!");
	else if (info->collect == 0)
		print_error("Map must have at least one collectible!");
	else if (info->player == 0)
		print_error("Map must have one starting position!");
	check_finish(info);
}
