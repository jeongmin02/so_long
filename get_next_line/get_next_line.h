/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:13:08 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/25 14:56:50 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_get_str(char *str);
char	*ft_get_remain_str(char *str);
size_t	ft_gnl_strlen(char *s);
int		ft_isnewline(char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);

#endif
