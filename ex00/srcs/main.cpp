/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:20:59 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/08 20:18:44 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	printError(std::string line, Btc& x, int i)
{
	if (x.errorData[i] == "Error: bad input => ")
		return (std::cerr << "Error: bad input => " << line << std::endl, 1)
	else if (x.errorData[i] == "Error: not a positive number.")
		return (std::cerr << "Error: not a positive number." << line << std::endl, 1)
	else if (x.errorData[i] == "Error: too large a number.")
		return (std::cerr << "Error: too large a number." << line << std::endl, 1)

	return (0);
}


int	checkValues(std::string lineRemainder, Btc& x, int i)
{
	if (lineRemainder[0] != ' ' || lineRemainder[1] != '|' 
				|| lineRemainder[2] != ' ')
	{
		x.errorData[i] = "Error: bad input => ";
		return (EXIT_FAILURE);
	}

	std::stringstream	valueString(lineRemainder.substr(3));
	float				valueFloat;
	valueString >> valueFloat;
	if (valueString.fail())
	{
		x.errorData[i] = "Error: bad input => ";
		return (EXIT_FAILURE);
	}

	if (valueFloat < 0)
	{
		x.errorData[i] = "Error: not a positive number.";
		return (EXIT_FAILURE);;
	}
	else if (valueFloat > 1000)
	{
		x.errorData[i] = "Error: too large a number.";
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


void	checkDatesAndValues(std::string line, Btc& x, int i)
{
	if (line.size() < 14)
	{
		x.errorData[i] = "Error: bad input => ";
		return ;
	}

	std::stringstream	yearString(line.substr(0, 4));
	std::stringstream	monthString(line.substr(5,2));
	std::stringstream	dayString(line.substr(8, 2));
	int					yearInt;
	int					monthInt;
	int					dayInt;

	yearString >> yearInt;
	monthString >> monthInt;
	dayString >> dayInt;
	if (yearString.fail() || monthString.fail() || dayString.fail())
	{
		x.errorData[i] = "Error: bad input => ";
		return ;
	}
	
	if (checkValues(line.substr(10), x, i) == EXIT_FAILURE)
		return ;

	x.errorData[i] = "success";
}

// the fstream function apparently start looking from the working directory
//  and not directory where the main is in
int	checkInputFile(char* argv1, Btc& x)
{
	if (!argv1 || strcmp(argv1, "input.txt"))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}	
	
	std::ifstream	inputFile("input.txt");
	if (!inputFile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}

	int				i = 0;
	std::string		line;
	std::getline(inputFile, line);
	if (line != "date | value")
		x.errorData[i] = "Error: bad input => ";
	else
		x.errorData[i] = "success";
	i++;
		
	while (std::getline(inputFile, line))
	{
		checkDatesAndValues(line, x, i);
		i++;
	}

	return (inputFile.close(), EXIT_SUCCESS);
}

int main(int argc, char** argv)
{
	Btc	data;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	if (checkInputFile(argv[1], data) == EXIT_FAILURE)
		return (EXIT_FAILURE);


	if (data.addExchangeData() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (data.executeExchange() == EXIT_FAILURE)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
