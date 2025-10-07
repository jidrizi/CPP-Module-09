/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:20:59 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/07 13:27:40 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Sadly I couldn't find a better looking way to code this because of course
// not every month has the same amount of days.
int	parseDay(int dayInt, int monthInt)
{

	if (dayInt < 1 || dayInt > 31)
		return (EXIT_FAILURE);

	if (dayInt > 29 && monthInt == 2)
		return (EXIT_FAILURE);
	else if (dayInt > 30 && 
		(monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11))
		return(EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

int	checkValues(std::string lineRemainder)
{

	if (lineRemainder[0] != ' ' || lineRemainder[1] != '|' || lineRemainder[2] != ' ')
		return (EXIT_FAILURE);

	std::stringstream	valueString(lineRemainder.substr(3));
	float				valueFloat;
	if (valueString >> valueFloat)
	{
		if (valueFloat < 0 || valueFloat > 1000)
			return (std::cerr << "4\n", EXIT_FAILURE);
	}
	else
		return (std::cerr << "6\n", EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}


int	checkDates(std::string line)
{
	
	std::stringstream	yearString(line.substr(0, 4));
	std::stringstream	monthString(line.substr(5,2));
	std::stringstream	dayString(line.substr(8, 2));
	int					yearInt;
	int					monthInt;
	int					dayInt;

	
	if (yearString >> yearInt)
	{
		if (yearInt < 2009 || yearInt > 2022)
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	
	if (monthString >> monthInt)
	{
		if (monthInt < 1 || monthInt > 12)
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);

	if (dayString >> dayInt)
	{
		if (parseDay(dayInt, monthInt) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	
	if (checkValues(line.substr(10)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// the fstream function apparently start looking from the working directory
//  and not directory where the main is in
int	parseInputFile(char *argv1)
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


	std::string		line;
	std::getline(inputFile, line);
	if (line != "date | value")
	{
		std::cerr << "Error: Input file content is not correct" << std::endl;
		return (EXIT_FAILURE);
	}

	while (std::getline(inputFile, line))
	{
		if (checkDates(line) == EXIT_FAILURE)
		{
			std::cerr << "Error: Input content is not correct" << std::endl;
			return (EXIT_FAILURE);
		}
	}

	return (inputFile.close(), EXIT_SUCCESS);
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	if (parseInputFile(argv[1]) != EXIT_FAILURE)
		return (EXIT_FAILURE);
	
	// btc	x;
	// x.executeExchange(argv[1]);
	return (EXIT_SUCCESS);
}
