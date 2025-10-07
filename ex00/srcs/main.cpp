/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:20:59 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/07 10:18:51 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	parseMap(char **argv)
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
		std::cerr << "Error: Map contents are not correct" << std::endl;
		return (EXIT_FAILURE);
	}

	while (std::getline(inputFile, line) != NULL)
	{
		if (parseDatesAndValues(line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return(file.close(), EXIT_SUCCESS);
}

int main(int argc, char** argv)
{
	if (argc != 2))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	if (parseMap(argv) != EXIT_FAILURE)
		return (EXIT_FAILURE);

	
	return(EXIT_SUCCESS);
}