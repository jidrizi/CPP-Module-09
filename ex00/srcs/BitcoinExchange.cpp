/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:56:35 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/09 14:41:46 by jidrizi          ###   ########.fr       */
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

// std::string	getClosestDate(std::string line)
// {
	
// }


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
	if (it == this->exchangeData.end())
		it = this->exchangeData.lower_bound(inputDate);

	float newInputValue = inputValue * it->second;
	std::cout << inputDate << " => " << inputValue
		<<	" = " << newInputValue << std::endl;

	return (EXIT_SUCCESS);
}

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
	}

	return (dataFile.close(), EXIT_SUCCESS);
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

	while (std::getline(inputFile, line) && line.empty() == false)
	{
		i++;
		if (printError(line, *this, i) == EXIT_FAILURE)
			continue ;
		if (this->findAndMulitply(line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}

	return (inputFile.close(), EXIT_SUCCESS);
}
