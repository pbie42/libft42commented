/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:42:13 by pbie              #+#    #+#             */
/*   Updated: 2015/11/30 14:49:00 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function writes the string s to the file descriptor fd followed by a
 * '\n' to make a new line. This function is exactly the same as our ft_putendl
 * function except that we take in a parameter for the file descriptor. We will
 * use our ft_putstr_fd and ft_putchar_fd functions to make this function work.
 * Please review ft_putstr_fd and ft_putchar_fd to understand the inner
 * workings of this function.*/

void		ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
