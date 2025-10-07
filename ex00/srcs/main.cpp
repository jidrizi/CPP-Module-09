/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:20:59 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/07 11:46:46 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Sadly I couldn't find a better looking way to code this because of course
// not every month has the same amount of days.
int	parseDay(int dayInt, int monthInt)
{

	if (dayInt < 0 || dayInt > 31)
		return (EXIT_FAILURE)

	if (dayInt > 29 && monthInt == 2)
		return (EXIT_FAILURE);
	else if (dayInt > 30 && 
		(monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11))
		return(EXIT_FAILURE);

	return (EXIT_SUCCESS)
}

int	checkDatesAndValues(std::string line, DatesAndValues &dav, int i)
{
	
	std::string	yearDate = line.substr(0, 4);
	std::string	monthDate = line.substr(5,2);
	std::string	dayDate = line.substr(8, 2);

	std::stringstream	yearInt(yearDate);
	if (yearInt.fail() || (yearInt < 2009 || yearInt > 2022))
		return (EXIT_FAILURE)
	else
		yearInt = dav[i].Date[0];

	std::stringstream	monthInt(monthDate);
	if (monthInt.fail() || (monthInt < 1 || monthInt > 12))
		return (EXIT_FAILURE)
	else
		yearInt = dav[i].Date[1];

	std::stringstream	dayInt(dayDate);
	if (dayInt.fail() || parseDay(dayInt, monthInt))
		return (EXIT_FAILURE)
	else
		dayInt = dav[i].Date[2];

	return (EXIT_SUCCESS);
}

int	parseInputFile(char **argv, DatesAndValues &dav)
{
	if (argv[1].empty() || argv[1] != "input.txt")
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE)
	}	
	
	std::ifstream	inputFile(argv[1]);
	if (!file)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE)
	}


	std::string		line;
	if (std::getline(inputFile, line) != "date | value")
	{
		std::cerr << "Error: Input content is not correct" << std::endl;
		return (EXIT_FAILURE);
	}

	int	i = 0;
	while (std::getline(inputFile, line))
	{
		if (checkDatesAndValues(line, dav, i) == EXIT_FAILURE)
		{
			std::cerr << "Error: Input content is not correct" << std::endl;
			return (EXIT_FAILURE);
		}
		i++;
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
	DatesAndValues	dav;
	if (parseInputFile(argv, dav) != EXIT_FAILURE)
		return (EXIT_FAILURE);

	
	return (EXIT_SUCCESS);
}
