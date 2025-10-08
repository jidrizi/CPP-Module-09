/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:56:35 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/08 20:24:48 by jidrizi          ###   ########.fr       */
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

int Btc::addExchangeData()
{	
	// remember fstream starts looking from working dir
	std::ifstream	dataFile("data.csv");
	if (!dataFile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}

	for (std::string line; std::getline(dataFile, line); )
	{
		std::string			dateString = line.substr(0, 10);
		std::stringstream	valueString(line.substr(11));
		float				valueFloat;

		valueString >> valueFloat;
		std::cout << valueFloat;
		this->exchangeData[dateString] = valueFloat;
	}

	return (dataFile.close(), EXIT_SUCCESS);
}

void	findAndMulitply(std::string line)
{
	
}

int	Btc::executeExchange()
{
	std::ifstream	inputFile("input.txt");
	if (!inputFile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}

	std::string	line;
	std::getline(inputFile, line);
	printError(line, *this, i);
	while (std::getline(inputFile, line))
	{
		if (printError(line, *this, i))
			continue ;
		
	}

	return (inputFile.close(), EXIT_SUCCESS);
}
