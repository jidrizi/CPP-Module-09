/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:20:59 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/08 14:19:49 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	checkValues(std::string lineRemainder)
{
	if (lineRemainder[0] != ' ' || lineRemainder[1] != '|' 
				|| lineRemainder[2] != ' ')
		return (MIDDLE_PART_BAD_INPUT);

	std::stringstream	valueString(lineRemainder.substr(3));
	float				valueFloat;
	valueString >> valueFloat;
	if (valueString.fail())
			return (MIDDLE_PART_BAD_INPUT);

	if (valueFloat < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (INVALID_LINES);
	}
	else if (valueFloat > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (INVALID_LINES);
	}

	return (EXIT_SUCCESS);
}


int	checkDatesAndValues(std::string line)
{
	
	if (line.size() < 14)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (INVALID_LINES);
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
		std::cerr << "Error: bad input => " << line << std::endl;
		return (INVALID_LINES);
	}
	
	int returnValue = checkValues(line.substr(10));
	if (returnValue == INVALID_LINES)
		return (INVALID_LINES);
	else if (returnValue == MIDDLE_PART_BAD_INPUT)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (INVALID_LINES);
	}

	return (EXIT_SUCCESS);
}

// the fstream function apparently start looking from the working directory
//  and not directory where the main is in
int	parseInputFile(char* argv1, Btc& x)
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

	int	i = 0;
	std::string		line;
	std::getline(inputFile, line);
	if (line != "date | value")
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		x.errorData[i] = "error";
	}
	else
		x.errorData[i] = "success";
	i++;
		
	while (std::getline(inputFile, line))
	{
		if (checkDatesAndValues(line) == INVALID_LINES)
			x.errorData[i] = "error";
		else
			x.errorData[i] = "success";
		i++;
	}

	return (inputFile.close(), EXIT_SUCCESS);
}

int main(int argc, char** argv)
{
	Btc	x;
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	if (parseInputFile(argv[1], x) != EXIT_FAILURE)
		return (EXIT_FAILURE);
	
	// x.executeExchange(argv[1]);
	return (EXIT_SUCCESS);
}
