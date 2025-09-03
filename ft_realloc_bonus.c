/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:38:05 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/09/03 12:38:06 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_realloc(void *ptr, size_t size, size_t extra_size)
{
	void	*new_ptr;

	if (!ptr)
		return (0);
	new_ptr = ft_calloc((size + extra_size), 1);
	if (!new_ptr)
		return (0);
	ft_memmove(new_ptr, ptr, size);
	free (ptr);
	return (new_ptr);
}
