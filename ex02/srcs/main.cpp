/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:08 by jidrizi           #+#    #+#             */
/*   Updated: 2026/01/19 22:21:56 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	errorMsg(std::string msgStr)
{
	std::cerr << "Error" << std::endl;
	std::cerr << msgStr << std::endl;

	return (EXIT_FAILURE);
}

int	findArgQuantity(char **argv)
{
	int	i = 0;

	for ( ; argv[0]; argv++)
		i++;
	return (i);
}

static int	checkDups(char** argv)
{
	int current = 0;
	int next = 1;

	while (argv[current])
	{
		while (argv[current + next])
		{
			if (strcmp(argv[current], argv[current + next]) == 0)
				return (EXIT_FAILURE);
			next++;
		}
		next = 1;
		current++;
	}

	return (EXIT_SUCCESS);
}

static int	checkArgs(int argc, char** argv)
{
	if ((argc - 1) < 4)
		return (errorMsg("Inputing less than 4 numbers is not allowed."));

	int	currStr = 1;
	int	currChar = 0;
	while (argv[currStr])
	{
		while (argv[currStr][currChar])
		{
			if (argv[currStr][currChar] && !std::isdigit(argv[currStr][currChar]))
				return (errorMsg("Only numbers allowed."));
			currChar++;
		}
		currChar = 0;
		currStr++;
	}

	if (checkDups(argv) == EXIT_FAILURE)
		return (errorMsg("No duplicates are allowed."));

	return (EXIT_SUCCESS);
}



int	main(int argc, char **argv)
{
	if (checkArgs(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	PmergeMe	containerHolder;
	containerHolder.getAndPushNumbers(argv);
	
	containerHolder.printContainerElements("Before:  ");
	containerHolder.executeFirstHalf(1);
	// containerHolder.printContainerElements("After:  ");

	return (EXIT_SUCCESS);
}