/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:53:45 by pbie              #+#    #+#             */
/*   Updated: 2015/11/27 18:12:32 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function that writes a single character to the standard output stream of
 * the terminal. This is one of the most basic and essential of all the
 * functions in our library. We use the write function to achieve our
 * desired output. The character we want to output is held in the ft_putchar
 * parameter variable char c. This can be any printable character which look to
 * our ft_isprint function to know which characters are printable.The 
 * first parameter in the write function is the file descriptor of where to
 * write the output. You can either use a file descriptor obtained from the
 * open system call, or you can use 0, 1, or 2, to refer to the standard input,
 * standard output, or standard error, respectively. In this case we want the
 * standard output so we use 1. The next parameter is a null terminated
 * character string of the content to write. We give the address to our char c
 * parameter. The last parameter is the number of bytes to write. Since we have
 * one character we want to write that is 1 byte so we put a 1 as the parameter.
 * This will place our char c to the standard output.*/

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
