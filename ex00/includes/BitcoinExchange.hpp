/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:21:33 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/07 11:52:48 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


// MACROS
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

// LIBRARIES 
# include <string>
# include <iostream>
# include <fstream>

// CLASSES

class DatesAndValues
{
	public:
		int	*Date[3];
		int value;	
}

#endif