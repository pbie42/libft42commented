/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:12:49 by pbie              #+#    #+#             */
/*   Updated: 2015/11/30 14:15:18 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function will display the string s on the standard output followed by a
 *'\n', which is a new line. We do this by using our ft_putstr and ft_putchar 
 * functions that we previously made. We use our ft_putstr on our string s to
 * display it on the standard output. Then we use our ft_putchar to have our
 * string followed by a new line.*/

void		ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
