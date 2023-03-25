/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:42:19 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/25 15:22:28 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_RED 17

typedef struct s_info
{
	struct s_ptr	*ptr;
	char			*map;
	char			*map_dfs;
	unsigned int	height;
	unsigned int	width;
	unsigned int	exit;
	unsigned int	exit_dfs;
	unsigned int	collect;
	unsigned int	collect_dfs;
	unsigned int	player;
	unsigned int	walk;
}	t_info;

typedef struct s_ptr
{
	void	*mlx;
	void	*mlx_win;
	void	*wall_ptr;
	void	*tile_ptr;
	void	*exit_ptr;
	void	*collect_ptr;
	void	*player_dir_ptr[4];
	void	*player_ptr[2];
}	t_ptr;

typedef struct s_sprite
{
	t_info	*info;
	t_ptr	*ptr;
	int		count;
}	t_sprite;

void	parse(int argc, char **argv, t_info *info);
void	check_rectangle(t_info *info);
void	check_wall(t_info *info);
void	check_element(t_info *info);
void	check_finish(t_info *info);
void	xpm_to_image(t_info *info, t_ptr *ptr);
int		exit_game(char *s_ptr);
void	print_error(char *str);
char	*delete_newline(char *str);
void	print_image(t_info *info, t_ptr *ptr);
void	put_image(t_info *info, t_ptr *ptr, unsigned int x, unsigned int y);
int		print_sprite_image(t_sprite *sprite);
int		key_press(int keycode, t_info *info);
char	*ft_free_strjoin(char const *s1, char const *s2);

#endif