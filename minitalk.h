/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:28:08 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/08/26 17:28:09 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>

# define CHUNK 131100

typedef struct s_str
{
	char	*str;
	int		i;
	int		end;
	int		cap;
}	t_str;

void	*ft_realloc(void *ptr, size_t size, size_t extra_size);

#endif