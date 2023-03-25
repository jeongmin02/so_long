/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:42:51 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/25 14:56:50 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

int	exit_game(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	print_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(1);
}

void	delete_newline(char *str)
{
	unsigned int	str_len;

	str_len = ft_strlen(str);
	if (str[str_len - 1] == '\n')
		str[str_len - 1] = '\0';
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 && s2)
		return (s2);
	else if (!s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	free(s2);
	return (str);
}
