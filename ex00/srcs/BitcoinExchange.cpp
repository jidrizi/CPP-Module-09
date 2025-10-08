/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:56:35 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/08 12:02:55 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors
Btc::Btc()
{
	std::cout << "\033[32mBtc default constructor called.\033[0m" 
			<< std::endl;
}

Btc::Btc(Btc& src) : exchangeData(src.exchangeData)
{
	std::cout << "\033[32mBtc copy constructor called.\033[0m" << std::endl;
}

Btc& Btc::operator=(Btc& src)
{
	std::cout << "\033[32mBtc copy assigment operator called.\033[0m" 
			<< std::endl;
	if (this != &src)
		this->exchangeData = src.exchangeData;
	return (*this);
}

Btc::~Btc()
{
	std::cout << "\033[32mBtc destructor called.\033[0m" << std::endl;
}


// Member functions
Btc::executeExchange(char* argv1)
{
	
}