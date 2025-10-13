/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:27:29 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/13 16:53:45 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isNum(char	c)
{
	if (c >= '0' && c <= '9')
		return (true);

	return (false);
}

bool	isOperand(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return (true);

	return (false);
}

int	checkElements(char *givenEquasion)
{
	for (int i = 0; givenEquasion[i]; i++)
	{
		if (isNum(givenEquasion[i]) == false && givenEquasion[i] != ' ')
		{
			if (isOperand(givenEquasion[i]) == false)
				return (std::cerr << "Error: elements are not correct\n", EXIT_FAILURE);
		}
		else if (isNum(givenEquasion[i]) == true)
		{
			if (givenEquasion[i + 1] && isNum(givenEquasion[i + 1]) == true)
				return (std::cerr << "Error: elements are not correct\n", EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}

int	main(int argc, char** argv)
{
	if (argc != 2)
		return (std::cerr << "Error: incorrect number of args", EXIT_FAILURE);
	if (checkElements(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
	RPN	stackHolder;
	if (stackHolder.receiveAndExecute(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}