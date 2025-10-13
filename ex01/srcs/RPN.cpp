/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:20:19 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/13 15:49:47 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors

RPN::RPN() : numAmountInStack(0)
{
	std::cout << "\033[32mRPN default constructor called.\033[0m" 
			<< std::endl;
}

RPN::RPN(RPN& src) : numAmountInStack(src.numAmountInStack) , rpnStack(src.rpnStack)
{
	std::cout << "\033[32mRPN copy constructor called.\033[0m" << std::endl;
}

RPN& RPN::operator=(RPN& src)
{
	std::cout << "\033[32mRPN copy assigment operator called.\033[0m" 
			<< std::endl;
	if (this != &src)
	{
		this->numAmountInStack = src.numAmountInStack;
		this->rpnStack = src.rpnStack;
	}
	return (*this);
}

RPN::~RPN()
{
	std::cout << "\033[32mRPN destructor called.\033[0m" << std::endl;
}


// Member functions

int	RPN::RecieveAndExecute(char* notation)
{
	int	i = 0;
	int	num = 0;

	while (notation[i])
	{
		while (notation[i] && notation[i] == ' ')
			i++;
		if (notation[i] && isOperand(notation[i]) == true && this->numAmountInStack < 2)
			return (EXIT_FAILURE);
		else if (notation[i] && isOperand(notation[i]) == true)
		{
			
		}
		else if (notation[i] && isOperand(notation[i]) == false)
		{
			num = notation[i] - '0';
			this->rpnStack.push(num);
			this->numAmountInStack++;
		}
		i++;
	}
}