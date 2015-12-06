/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:43:26 by pbie              #+#    #+#             */
/*   Updated: 2015/12/03 15:53:18 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function allocates memory and returns a 'fresh' string of characters
 * terminated with a '\0' that is the char equivalent of the int passed in
 * the parameter. Negative numbers should be managed as well. If the allocation
 * fails the function will return NULL. NOTE: This is a recursive function. If
 * you are unfamiliar with recursive functions it is a function which either
 * calls itself or is in a potential cycle of function calls.*/

char		*ft_itoa(int n)
{
	/*We start by creating a char string variable. This is what our function
	 * will return. We then allocate memory for our string variable str. NOTE:
	 * We only allocate memory for a size of 2 char values. This is because
	 * we will be doing this function recusively and we want to allocate memory
	 * only as we need it. We do a size of 2 in our malloc function because we
	 * want to do one character at a time from the given int n, one space for
	 * the one digit number converted to a char and the terminating '\0' that
	 * is needed to finish that individual char's string. If the allocation
	 * fails we return NULL. We also want to compensate for the chance the int
	 * passed to us is the smallest integer possible. If we are passed that
	 * number into our parameter we make sure we return a string of it.*/
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	/*Next we want to see if the int that is passed in our parameter is a
	 * negative number. If int n is less than zero then we make our 'fresh'
	 * string str's index position 0 a negative sign and postion 1 a
	 * terminating '\0'. We then set string str equal to ft_strjoin with our
	 * str as a parameter and we recursively call our function with a -n so as
	 * to turn the negative int into a postive. We then start the function over
	 * again.*/
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	/*Below we are saying if the int n passed in our paramter is greater than
	 * 10 that we want to break it down recursively so we can build it back
	 * up as a string. We do this by setting our memory allocated string str
	 * equal to our previously made ft_strjoin function and pass it the
	 * parameter of our ft_itoa function with n divided by 10 and our ft_itoa
	 * function with n modulus 10. This is where the idea of how recursion 
	 * works can be hard to understand. This use of ft_strjoin will not happen 
	 * until later because we are calling ft_itoa again. This will divide our
	 * given int by 10 and take the result and start the function over again,
	 * consitently breaking it down until we have the very first number in our
	 * int. For example if we started with the number n = 123 our call of
	 * ft_itoa(n / 10) and ft_itoa(n % 10) is really ft_itoa(123 / 10) and
	 * ft_itoa(123 % 10). This will call ft_itoa on a value of 12 for the
	 * division by 10 and call ft_itoa on the value of 3 for our modulus 10.
	 * This is how we break down the number into individual digits. For our
	 * result of 3 it will begin this function over again and skip this section
	 * since it will now be a value that is less than 10. We see in our next 
	 * else if statment that if the number is greater than 0 and less than 10
	 * we convert it here into an indiviual string that would be "3\0" because
	 * we must have a terminating '\0'. This individual string will be
	 * returned to the ft_strjoin function it was called in to be joined
	 * with the string that will be return from its fellow parameter. But what
	 * has happened to the ft_itoa(123 / 10)? Well that has given us the number
	 * 12 to put into this ft_itoa function. Since this number is still greater
	 * than 10 we will the if statement that will use ft_strjoin with the
	 * two ft_itoa functions passed into it's paramters, but this time on the
	 * value of 12. As has happened earlier with the full value of 123 we will
	 * be splitting this 12 now into an individual 1 and 2. Running ft_itoa on
	 * each individual number. Since both numbers are a value less than 10 but
	 * greater than 0 we will convert them each into a string. So at this point
	 * we now have the strings "1\0", "2\0", and from our earlier call of 
	 * ft_itoa(123 % 10) we have the string "3\0". Since we have reached an end
	 * return point for our recursion we will be combining first the strings
	 * "1\0" and "2\0" inside the ft_strjoin function they are currently inside
	 * making them into the string "12\0". This brings us back up a level in 
	 * our recursion to now join "12\0" with the string "3\0" making the string
	 * "123\0". Since this has been placed now into our string str (NOTE: we
	 * have been allocating memory for each string on each call of ft_itoa in
	 * our recursion) we can return it now that the entire number has been
	 * converted into a char string. Thus ending our function. If this has been
	 * hard to picture in your head try walking the function through on a piece
	 * of paper. It should break down as sort of a binary tree.*/
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}
