/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:20:50 by jerhee          #+#    #+#             */
/*   Updated: 2021/11/30 03:35:56 by jerhee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	if (!dst && !src)
		return (NULL);
	ret = dst;
	if (dst > src)
	{
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	}
	else
	{
		while (len--)
			*(unsigned char *)(dst++) = *(unsigned char *)(src++);
	}
	return (ret);
}
