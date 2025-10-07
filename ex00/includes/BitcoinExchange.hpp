/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:21:33 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/07 13:13:35 by jidrizi          ###   ########.fr       */
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
# include <cstring>
# include <sstream>
# include <fstream>

// CLASSES

class btc
{
	public:
		void	executeExchange(char *argv1);
};

#endif