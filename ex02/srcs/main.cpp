/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:08 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/19 18:11:05 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	checkArgs(int argc, char** argv)
{
	if (argc < 2)
		return (std::cerr << "Error: not enough arguments.", EXIT_FAILURE);

	argv++;
	while (*argv)
	{
		std::stringstream	numberStr(*argv);
		int					numberInt;

		numberStr >> numberInt;
		if (numberStr.fail() || numberInt < 0)
			return (std::cerr << "Error: something wrong with arguments"
					, EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}



int	main(int argc, char** argv)
{
	if (checkArgs(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
}