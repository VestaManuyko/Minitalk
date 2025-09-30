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

# define CHUNK 131080

typedef struct s_str
{
	char					*str;
	int						i;
	volatile sig_atomic_t	end;
}	t_str;

#endif