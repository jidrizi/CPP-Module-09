/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:08 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/21 19:54:51 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	checkDups(char** argv)
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

int	checkArgs(int argc, char** argv)
{
	if (argc < 3)
		return (std::cerr << "Error: not enough arguments.\n", EXIT_FAILURE);

	int	currStr = 1;
	int	currChar = 0;
	while (argv[currStr])
	{
		while (argv[currStr][currChar])
		{
			if (argv[currStr][currChar] 
					&& (argv[currStr][currChar] < '0' || argv[currStr][currChar] > '9'))
			{
				return (std::cerr << "Error: only numbers allowed\n", 
							EXIT_FAILURE);
			}
			currChar++;
		}
		currChar = 0;
		currStr++;
	}

	if (checkDups(argv) == EXIT_FAILURE)
		return (std::cerr << "Error: no duplicate allowed\n", EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

int	main(int argc, char** argv)
{
	if (checkArgs(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	PmergeMe	containerClass;
	// if (argc  == 3)
	// 	executeMini(containerClass);
	// else
		containerClass.executeVectorSort(argv);
		// containerClass->executeDequeSort(argv);
	
	return (EXIT_SUCCESS);
}