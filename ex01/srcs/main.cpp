/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 17:27:29 by jidrizi           #+#    #+#             */
/*   Updated: 2025-10-09 17:27:29 by jidrizi          ###   ########he        */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//ugly because I couldn't think of a better way that wasn't a waste of time
int	checkElements(char *givenEquasion)
{
	for (int i = 0; givenEquasion[i]; i++)
	{
		if (givenEquasion[i] < '0' || givenEquasion[i] > '9' || givenEquasion[i] != ' ')
		{
			if (givenEquasion[i] != '+' || givenEquasion[i] != '-' || givenEquasion[i] != '*' || givenEquasion[i] != '/')
				return (std::cerr << "Error: elements not correct\n", EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	RecieveElements(RPN& stackHolder)
{
	

	
}


int	main(int argc, char** argv)
{
	if (argc != 2)
		return (std::cerr << "Error: incorrect number of args", EXIT_FAILURE);
	if (checkElements(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
	RPN	stackHolder;
	

	return (EXIT_SUCCESS);
}