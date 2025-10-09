/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:56:35 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/09 11:14:12 by jidrizi          ###   ########.fr       */
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

	std::string	line;
	std::getline(dataFile, line);

	while (std::getline(dataFile, line))
	{
		std::string			dateString = line.substr(0, 10);
		std::stringstream	valueString(line.substr(11));
		float				valueFloat;

		valueString >> valueFloat;
		this->exchangeData[dateString] = valueFloat;
		std::cout << line << std::endl;
	}

	return (dataFile.close(), EXIT_SUCCESS);
}

int	Btc::findAndMulitply(std::string line)
{
	std::string			inputDate = line.substr(0, 10);
	std::stringstream	inputValStr(line.substr(13));
	float				inputValue;

	inputValStr >> inputValue;
	if (inputValStr.fail())
		return (EXIT_FAILURE);

	std::map<std::string, float>::iterator	it 
				= this->exchangeData.find(inputDate);
	int newInputValue = inputValue * it->second;
	std::cout << inputDate << " => " << inputValue << " = " << newInputValue
			<< std::endl;

	return (EXIT_SUCCESS);
}

int	Btc::executeExchange()
{
	std::ifstream	inputFile("input.txt");
	if (!inputFile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}

	int i = 0;
	std::string	line;
	std::getline(inputFile, line);
	printError(line, *this, i);
	i++;

	while (std::getline(inputFile, line))
	{
		if (printError(line, *this, i) == EXIT_FAILURE)
			continue ;
		if (this->findAndMulitply(line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}

	return (inputFile.close(), EXIT_SUCCESS);
}
