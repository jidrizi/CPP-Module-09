/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:56:35 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/08 15:04:19 by jidrizi          ###   ########.fr       */
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
void Btc::executeExchange()
{

	std::cout << "\n\nExecute time\n";
	
	// remember fstream starts looking from working dir
	std::ifstream	inputFile("input.txt");
	if (!inputFile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string			skipFirstLine;
	std::getline(inputFile, skipFirstLine);

	
	int					i = 1;
	for (std::string line; std::getline(inputFile, line); i++)
	{
		if (this->errorData[i] == "error")
			continue ;

		std::stringstream	valueString(line.substr(13));
		float				valueFloat;
		valueString >> valueFloat;
		std::cout << valueFloat << std::endl;
	}
}