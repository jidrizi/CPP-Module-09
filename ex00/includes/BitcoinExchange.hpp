/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:21:33 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/08 16:32:32 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


// MACROS

# ifndef MIDDLE_PART_BAD_INPUT
#  define MIDDLE_PART_BAD_INPUT 2
# endif

# ifndef INVALID_LINES
#  define INVALID_LINES 1
# endif

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

// LIBRARIES 
# include <string>
# include <iostream>
# include <cstring>
# include <sstream>
# include <fstream>
# include <map>

// CLASSES

class Btc
{
	private:
		std::map<std::string, float>	exchangeData;
	public:
	// Constructors
		Btc();
		Btc(Btc& src);
		Btc& 	operator=(Btc& src);
		~Btc();
	
	// Members
		std::map<int, std::string>		errorData;
		void	addSuccessfulLinesData();
		void	executeExchange();
};

#endif